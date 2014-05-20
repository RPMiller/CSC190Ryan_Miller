#pragma once
#include<Vector2.h>
#include<Core.h>
#include "Matrix3.h"

class Shape
{
	const Vector2* lines;
	Matrix3 translationMatrix;
	int numOfLines;
	float width;
	float height;
public:
	Shape(Vector2* lines,int numOfLines,Matrix3 translationMatrix);
	Shape(){}
	~Shape();
	void DrawShape(Core::Graphics graphics);
	void UpdateShape(Core::Graphics graphics,int x, int y,float dt);
	float GetWidth();
	float GetHeight();
	operator float*(){return translationMatrix;}
	void SetTranslationMatrix(Matrix3 translationMatrix);
	void SetPosition(Vector2 position);
	Matrix3 GetTranslationMatrix();
};

