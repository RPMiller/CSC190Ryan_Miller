#include "GameObject.h"


GameObject::GameObject()
{
	radsRotated = 0.0f;
}


GameObject::~GameObject(void)
{
}

Matrix3 GameObject::GetTranslationMatrix()
{
	return translationMatrix;
}

void GameObject::Draw(Core::Graphics graphics)
{
	position = position + velocity;

	translationMatrix = Matrix3();
	translationMatrix.Translate(position);
	Matrix3 drawMatrix;
	drawMatrix.Rotate(radsRotated);
	translationMatrix = drawMatrix * translationMatrix;
	for(int i = 0 ; i < numberOfShapes ; i++)
	{
		(shapes + i)->SetTranslationMatrix(translationMatrix);
		(shapes + i)->DrawShape(graphics);
	}
}

void GameObject::Update(Vector2 accelerationVector)
{
	Matrix3 rotation;
	rotation.Rotate(radsRotated);
	velocity = velocity + ((acceleration * accelerationVector) * rotation);
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