#include "GameObject.h"


GameObject::GameObject()
{
	radsRotated = 0.0f;
	isAlive = true;
	color = Color(0,200,200);
}


GameObject::~GameObject(void)
{
	//delete[] shapes;
}

Matrix3 GameObject::GetTranslationMatrix()
{
	return translationMatrix;
}

void GameObject::Draw(Core::Graphics graphics)
{
	if(isAlive)
	{
	translationMatrix = Matrix3();
	translationMatrix.Translate(position);
	Matrix3 drawMatrix;
	drawMatrix.Rotate(radsRotated);
	translationMatrix = drawMatrix * translationMatrix;
	for(int i = 0 ; i < numberOfShapes ; i++)
	{
		if(shouldVaryColor)
		{
			graphics.SetColor(this->VaryColor());
		}
		(shapes + i)->SetTranslationMatrix(translationMatrix);
		(shapes + i)->DrawShape(graphics);
	}
	graphics.SetColor(RGB(0,255,255));
	}
}

void GameObject::Update(Vector2 accelerationVector,float dt)
{
	if(isAlive)
	{
	Matrix3 rotation;
	rotation.Rotate(radsRotated);
	velocity = velocity + ((acceleration * dt * accelerationVector) * rotation);
	position = position + velocity;
	}
}

void GameObject::Update(float dt)
{
	Matrix3 rotation;
	rotation.Rotate(radsRotated);
	position = position + velocity * dt;
}

void GameObject::SetPosition(Vector2 position)
{
	GameObject::position = position;
	for(int i = 0 ; i < numberOfShapes ; i++)
	{
		(shapes + i)->SetPosition(position);
	}
}

void GameObject::Rotate(float rads)
{
	radsRotated += rads;
}

float GameObject::GetHeight()
{
	if(height == 0)
	{
		for(int i = 0; i < numberOfShapes; i++)
		{
			float shapeHeight = (shapes + i)->GetHeight();
			if(height < shapeHeight)
			{
				height = shapeHeight;
			}
		}
	}
	return height;
}

float GameObject::GetWidth()
{
	if(width == 0)
	{
		for(int i = 0; i < numberOfShapes; i++)
		{
			float shapeWidth = (shapes + i)->GetWidth();
			if(height < shapeWidth)
			{
				width = shapeWidth;
			}
		}
	}
	return width;
}

void GameObject::SetVelocity(Vector2 vel)
{
	velocity = vel;
}

Vector2 GameObject::GetVelocity()
{
	return velocity;
}

Vector2 GameObject::GetPosition()
{
	return position;
}

Core::RGB GameObject::VaryColor()
{
	Color next = randomGenerator.GenerateVaryRandomColor(color,200);
	return RGB(next.red,next.green,next.blue);
}