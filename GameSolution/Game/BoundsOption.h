#pragma once
#include<Core.h>
#include "Vector2.h"
#include "GameObject.h"

class BoundsOption
{
public:
	BoundsOption(void);
	~BoundsOption(void);
	virtual void CheckBounds(GameObject* gameObject,float screenHeight,float screenWidth)=0;
};

