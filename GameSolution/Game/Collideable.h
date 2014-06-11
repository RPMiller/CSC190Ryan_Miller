#pragma once
#include "Missile.h"
#include "GameObject.h"
#include "ExplosionParticleEffect.h"

class Collideable : public GameObject
{
protected:
	float health;
	bool shouldVaryColor;
	float damageBlinkTime;
	float damageBlinkMaxTime;
	Color damageColor;
	Color normalColor;
public:
	Collideable(void);
	~Collideable(void);
	virtual bool CheckCollision(Missile* missile);
	float GetHealth();
	virtual ExplosionParticleEffect* ExplodeObject() = 0;
	virtual void Update(Vector3 accelerationVector,float dt);
	virtual void Update(float dt);
};

