#pragma once
#include "GameObject.h"
#include "BeamShape.h"

class Missile : public GameObject
{
	float ticksOfLife;
	BeamShape* beam;
public:
	Missile(Vector3 position, Vector3 velocity,float ticks);
	~Missile(void);
	bool CheckDead();
	void Update(float dt);
	void Draw(Core::Graphics graphics);
};

