#pragma once
#include "boundsoption.h"
class WallOption :
	public BoundsOption
{
public:
	WallOption(void);
	~WallOption(void);
	void CheckBounds(GameObject* gameObject,float screenHeight,float screenWidth);
};

