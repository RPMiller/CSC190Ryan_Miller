#pragma once
#include "Missile.h"
#include "ExplosionParticleEffect.h"
#include "Collideable.h"

class Enemy : public Collideable
{
public:
	//virtual ExplosionParticleEffect* ExplodeObject() = 0;
	virtual void Init(Vector3 position) = 0;
	virtual void FollowHero(Vector3 heroPosition, float dt) = 0;
	virtual Missile** GetMissiles() = 0;
	virtual int GetTotalMissileNumber() = 0;
	virtual bool AreMissilesFromOneTurret() = 0;
};