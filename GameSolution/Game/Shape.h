#pragma once
#include<Vector2.h>
#include<Core.h>
class Shape
{
	const Vector2* lines;
	Vector2 position;
	int numOfLines;
	float width;
	float height;
public:
	Shape(Vector2* lines,int numOfLines,Vector2 position);
	Shape(){}
	~Shape();
	void DrawShape(Core::Graphics graphics);
	void UpdateShape(Core::Graphics graphics,int x, int y,float dt);
	float GetWidth();
	float GetHeight();
	operator float*(){return position;}
	void SetPosition(Vector2 position);
	Vector2 GetPosition();
};

