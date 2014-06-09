#pragma once
#include "Shape.h"
#include "Matrix4.h"
#include "Color.h"
#include "RandomGenerator.h"
#include "ShapeBuilder.h"

class GameObject
{
protected :
	Shape* shapes;
	Matrix4 translationMatrix;
	Vector3 velocity;
	Vector3 position;
	float height,width,depth;
	float acceleration;
	float radsRotatedAroundZ;
	float radsRotatedAroundX;
	int numberOfShapes;
	RandomGenerator randomGenerator;
	Color color;
	bool shouldVaryColor;


public:
	GameObject();
	~GameObject(void);
	virtual void Init(Vector3 position){position = Vector3(0,0,0); return;}
	float GetHeight();
	float GetWidth();
	float GetDepth();
	Matrix4 GetTranslationMatrix();
	virtual void SetPosition(Vector3 position);
	virtual void Draw(Core::Graphics graphics);
	virtual void Update(Vector3 accelerationVector,float dt);
	virtual void Update(float dt);
	void SetVelocity(Vector3 vel);
	Vector3 GetPosition();
	Vector3 GetVelocity();
	void RotateAroundZ(float rads);
	void RotateAroundX(float rads);
	bool isAlive;
	Core::RGB VaryColor();
	void SetColor(Color color);
	Color GetColor();
};

