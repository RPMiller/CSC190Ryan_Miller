#pragma once
#include "gameobject.h"
class Lerper :
	public GameObject
{
	Vector2* wayPoints;
	int currentWayPointIndex;
public:
	Lerper(void);
	~Lerper(void);
	void Init(Vector2 position);
	void Update(Vector2 accelerationVector);
};

