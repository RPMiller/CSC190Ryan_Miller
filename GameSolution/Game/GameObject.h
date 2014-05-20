#pragma once
#include "Shape.h"
#include "Matrix3.h"

class GameObject
{
protected :
	Shape* shapes;
	Matrix3 translationMatrix;
	Vector2 velocity;
	Vector2 position;
	float height;
	float width;
	float acceleration;
	float radsRotated;
	int numberOfShapes;

public:
	GameObject();
	~GameObject(void);
	virtual void Init(Vector2 position){position = Vector2(0,0); return;}
	float GetHeight();
	float GetWidth();
	Matrix3 GetTranslationMatrix();
	void SetPosition(Vector2 position);
	virtual void Draw(Core::Graphics graphics);
	virtual void Update(Vector2 accelerationVector);
	void SetVelocity(Vector2 vel);
	Vector2 GetPosition();
	Vector2 GetVelocity();
	void Rotate(float rads);
};

