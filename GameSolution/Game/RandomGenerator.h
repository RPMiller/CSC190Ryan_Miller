#pragma once
#include "Vector2.h"
#include "Color.h"

class RandomGenerator
{
	int VaryColorValue(int pixelValue, int range);
public:
	RandomGenerator(void);
	~RandomGenerator(void);
	Vector2 GenerateRandomUnitVector();
	Vector2 GenerateRandomVector(float xMin, float xMax,float yMin, float yMax);
	float GenerateRandomFloat(float min,float max);
	float GenerateRandomFloat();
	Color GenerateVaryRandomColor(Color base,int range);
};

