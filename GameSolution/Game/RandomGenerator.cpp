#include "RandomGenerator.h"
#include "Matrix3.h"


RandomGenerator::RandomGenerator(void)
{
	
}


RandomGenerator::~RandomGenerator(void)
{
}

Vector2 RandomGenerator::GenerateRandomUnitVector()
{
	return Vector2(GenerateRandomFloat(-1,1),GenerateRandomFloat(-1,1));
}

Vector2 RandomGenerator::GenerateRandomVector(float xMin, float xMax,float yMin, float yMax)
{
	return Vector2(GenerateRandomFloat(xMin,xMax),GenerateRandomFloat(yMin,yMax));
}

float RandomGenerator::GenerateRandomFloat(float min,float max)
{
	return GenerateRandomFloat() * (max - min) + min;
}

float RandomGenerator::GenerateRandomFloat()
{
	return (float)rand() / RAND_MAX;
}

Color RandomGenerator::GenerateVaryRandomColor(Color base,int range)
{
	int r = VaryColorValue(base.red,range);
	int g = VaryColorValue(base.green,range);
	int b = VaryColorValue(base.blue,range);
	return Color(r,g,b);
}

int RandomGenerator::VaryColorValue(int pixelValue, int range)
{
	int halfRange = range /2;
	int randomValue = (int)GenerateRandomFloat((float)-halfRange,(float)halfRange);
	pixelValue += randomValue;
	
	if(pixelValue > 255)
	{
		pixelValue = 255;
	}
	else if(pixelValue < 0)
	{
		pixelValue = 0;
	}

	return pixelValue;
}