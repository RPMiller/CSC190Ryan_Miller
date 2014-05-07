#pragma once
#include "Shape.h"

class GameObject
{
protected :
	Shape* shapes;
	Vector2 position;
	Vector2 velocity;
	int numberOfShapes;
	float height;
	float width;
	float acceleration;
public:
	GameObject();
	~GameObject(void);
	virtual void Init(Vector2 position){position = Vector2(0,0); return;}
	float GetHeight();
	float GetWidth();
	Vector2 GetPosition();
	void SetPosition(Vector2 position);
	void Draw(Core::Graphics graphics);
	virtual void Update(Vector2 accelerationVector);
	void SetVelocity(Vector2 vel);
	Vector2 GetVelocity();
};

