#pragma once
#include "Shape.h"

class ShapeBuilder
{
public:
	static const int CUBE_SHAPES_NUMBER = 6;
	ShapeBuilder(void);
	~ShapeBuilder(void);
	static void BuildCube(float size,Shape* shapes,int startIndex);
	static void BuildTriangle(Vector3 point1,Vector3 point2,Vector3 point3,Shape* shapes,int &startIndex);
	static void BuildQuad(Vector3 point1,Vector3 point2,Vector3 point3,Vector3 point4,Shape* shapes,int &startIndex);
};
