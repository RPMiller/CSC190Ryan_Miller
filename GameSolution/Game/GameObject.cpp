#include "GameObject.h"


GameObject::GameObject()
{
	radsRotatedAroundZ = 0.0f;
	radsRotatedAroundX = 0.0f;
	height = 0;
	width = 0;
	depth = 0;
	isAlive = true;
	color = Color(0,200,200);
}


GameObject::~GameObject(void)
{

}

void GameObject::Destroy()
{
	for(int i =0; i < numberOfShapes; i++)
	{
		shapes[i].Destroy();
	}
	if(numberOfShapes > 0)
	{
		delete[] shapes;
	}
}

Matrix4 GameObject::GetTranslationMatrix()
{
	return translationMatrix;
}

void GameObject::Draw(Core::Graphics graphics)
{
	if(isAlive)
	{
	translationMatrix = Matrix4();
	translationMatrix.Translate(position);
	Matrix4 drawMatrix;
	drawMatrix.RotateAroundZ(radsRotatedAroundZ);
	drawMatrix.RotateAroundX(radsRotatedAroundX);
	translationMatrix = drawMatrix * translationMatrix;
	for(int i = 0 ; i < numberOfShapes ; i++)
	{
		if(shouldVaryColor)
		{
			graphics.SetColor(this->VaryColor());
		}
		(shapes + i)->SetTranslationMatrix(translationMatrix);
		(shapes + i)->DrawShape(graphics,position);
	}
		if(shouldVaryColor)
		{
			graphics.SetColor(RGB(0,255,255));
		}
	}
}

void GameObject::Update(Vector3 accelerationVector,float dt)
{
	if(isAlive)
	{
		Matrix4 rotation;
		rotation.RotateAroundZ(radsRotatedAroundZ);
		rotation.RotateAroundX(radsRotatedAroundX);
		velocity = velocity + ((acceleration * dt * accelerationVector) * rotation);
		position = position + velocity;
	}
}

void GameObject::Update(float dt)
{
	position = position + velocity * dt;
}

void GameObject::SetPosition(Vector3 position)
{
	GameObject::position = position;
	for(int i = 0 ; i < numberOfShapes ; i++)
	{
		(shapes + i)->SetPosition(position);
	}
}

void GameObject::RotateAroundZ(float rads)
{
	radsRotatedAroundZ += rads;
}

void GameObject::RotateAroundX(float rads)
{
	radsRotatedAroundX += rads;
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
			if(width < shapeWidth)
			{
				width = shapeWidth;
			}
		}
	}
	return width;
}

float GameObject::GetDepth()
{
	if(depth == 0)
	{
		for(int i = 0; i < numberOfShapes; i++)
		{
			float shapeDepth = (shapes + i)->GetDepth();
			if(depth < shapeDepth)
			{
				depth = shapeDepth;
			}
		}
	}
	return width;
}

void GameObject::SetVelocity(Vector3 vel)
{
	velocity = vel;
}

Vector3 GameObject::GetVelocity()
{
	return velocity;
}

Vector3 GameObject::GetPosition()
{
	return position;
}

Core::RGB GameObject::VaryColor()
{
	Color next = randomGenerator.GenerateVaryRandomColor(color,200);
	return RGB(next.red,next.green,next.blue);
}

void GameObject::SetColor(Color color)
{
	GameObject::color = color;
}

Color GameObject::GetColor()
{
	return color;
}