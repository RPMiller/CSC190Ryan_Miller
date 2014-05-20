#pragma once
#include "GameObject.h"
class RecursiveRotation : public GameObject
{
public:
	const int NUM_RECURSE;
	const int RECURSE_DISTANCE;
	Shape* recurse;
	RecursiveRotation(int numRecurse,int recurseDistance,Vector2 center);
	~RecursiveRotation(void);
	void Rotate(float radsToRotate,Core::Graphics graphics);
	void RotateShapes(Shape parent, Shape child,int childIndex,Core::Graphics graphics);
	RecursiveRotation& operator=(const RecursiveRotation &tmp);
};

