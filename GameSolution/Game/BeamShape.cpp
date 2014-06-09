#include "BeamShape.h"


BeamShape::BeamShape(void)
{
	ticksOfGrowth = 3;
	Init();
}


BeamShape::~BeamShape(void)
{
}

BeamShape::BeamShape(float ticksOfGrowth) : ticksOfGrowth(ticksOfGrowth)
{
	Init();
}

void BeamShape::Init()
{
	numOfLines = 2;
	lines = new Vector3[numOfLines];
	lines[0] = Vector3(0,0,1);
	lines[1] = Vector3(0,0,0);
	height = 0;
	width = 0;
	depth = 0;
}
	
void BeamShape::Update(float dt)
{
	if(ticksOfGrowth>0)
	{
		height = 0;
		width = 0;
		depth = 0;
		Vector3 vector = lines[0];
		lines[0] = Vector3(vector.x,vector.y,vector.z + (80 * dt));
	}
}