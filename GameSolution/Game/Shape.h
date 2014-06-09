#pragma once
#include<Vector3.h>
#include<Core.h>
#include "Matrix4.h"
#include "MyMathUtil.h"

class Shape
{
protected:
	Vector3* lines;
	Matrix4 translationMatrix;
	int numOfLines;
	float width, height, depth;
	MyMathUtil mathUtil;
public:
	Shape(Vector3* lines,int numOfLines,Matrix4 translationMatrix);
	Shape(){}
	~Shape();
	void DrawShape(Core::Graphics graphics,Vector3 center);
	void UpdateShape(Core::Graphics graphics,int x, int y,float dt);
	float GetWidth();
	float GetHeight();
	float GetDepth();
	operator float*(){return translationMatrix;}
	void SetTranslationMatrix(Matrix4 translationMatrix);
	void SetPosition(Vector3 position);
	Matrix4 GetTranslationMatrix();
};

