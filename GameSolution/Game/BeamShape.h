#pragma once
#include "Shape.h"

class BeamShape : public Shape
{
	float ticksOfGrowth;
	void Init();
public:
	BeamShape(void);
	~BeamShape(void);

	BeamShape(float ticksOfGrowth);
	void Update(float dt);

	// conversion from Shape (assignment):
	BeamShape& operator= (const Shape& x) 
	{
		//stupid warning
		x;
		return *this;
	}
};

