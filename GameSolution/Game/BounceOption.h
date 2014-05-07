#pragma once
#include "BoundsOption.h"
class BounceOption : public BoundsOption
{
public:
	BounceOption(void);
	~BounceOption(void);
	void CheckBounds(GameObject* gameObject,float screenHeight,float screenWidth);
};

