#pragma once
#include "GameObject.h"
class Missile : public GameObject
{
	int ticksOfLife;
public:
	Missile(Vector2 position, Vector2 velocity);
	~Missile(void);
	bool CheckDead();
	void Draw(Core::Graphics graphics);
};

