#pragma once
#include "GameObject.h"
class Missile : public GameObject
{
	float ticksOfLife;
public:
	Missile(Vector2 position, Vector2 velocity);
	~Missile(void);
	bool CheckDead();
	void Update(float dt);
	void Draw(Core::Graphics graphics);
};

