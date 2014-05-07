#pragma once
#include "boundsoption.h"
class WrapOption :
	public BoundsOption
{
public:
	WrapOption(void);
	~WrapOption(void);
	void CheckBounds(GameObject* gameObject,float screenHeight,float screenWidth);
};

