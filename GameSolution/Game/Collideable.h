#pragma once
#include "Missile.h"
#include "GameObject.h"
#include "ExplosionParticleEffect.h"

class Collideable : public GameObject
{
protected:
	float health;
public:
	Collideable(void);
	~Collideable(void);
	virtual bool CheckCollision(Missile* missile);
	float GetHealth();
	virtual ExplosionParticleEffect* ExplodeObject() = 0;
};

