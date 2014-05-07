#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject(void)
{
}

Vector2 GameObject::GetPosition()
{
	return position;
}

void GameObject::Draw(Core::Graphics graphics)
{
	position = position + velocity;
	for(int i = 0 ; i < numberOfShapes ; i++)
	{
		(shapes + i)->SetPosition(position);
		(shapes + i)->DrawShape(graphics);
	}
}

void GameObject::Update(Vector2 accelerationVector)
{
	velocity = velocity + (acceleration * accelerationVector);
}

void GameObject::SetPosition(Vector2 position)
{
	GameObject::position = position;
	for(int i = 0 ; i < numberOfShapes ; i++)
	{
		(shapes + i)->SetPosition(position);
	}
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