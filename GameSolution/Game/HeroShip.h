#pragma once
#include "Collideable.h"
#include "Turret.h"
#include "Missile.h"
#include "FountainParticleEffect.h"
#include "BasicTurret.h"

class HeroShip :
	public Collideable
{
public:
	Turret turret;
	HeroShip(void);
	~HeroShip(void);
	void Init(Vector3 position);
	void Draw(Core::Graphics graphics);
	void Update(Vector3 accelerationVector,float dt);
	void Update(float dt);
	void Fire();
	ExplosionParticleEffect* ExplodeObject();
	Vector3 MaxVelocity;

	virtual void Destroy();
};