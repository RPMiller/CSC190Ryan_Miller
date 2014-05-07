#pragma once
#include "BounceOption.h"

class ArbitraryBounceOption : public BoundsOption
{
	BounceOption bounceOption;

	void IsInBounds(Vector2 shipFromWall,Vector2 shipFromWallAfterMove,Vector2 wall,GameObject* gameObject);
public:
	ArbitraryBounceOption(void);
	~ArbitraryBounceOption(void);
	void CheckBounds(GameObject* gameObject,float screenHeight,float screenWidth);
};

