#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include<math.h>
#include "ScreenConstants.h"

class MyMathUtil
{
	Vector3 center;
	//Vector2 x,y,z;
public:
	MyMathUtil(void);
	~MyMathUtil(void);
	Vector2 TranslateTo2D(Vector3 vector);
};

