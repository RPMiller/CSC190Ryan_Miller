#pragma once
#include "gameobject.h"
#include "Turret.h"
#include "Missile.h"
#include "FountainParticleEffect.h"

class HeroShip :
	public GameObject
{
	FountainParticleEffect* fountain;

public:
	Turret turret;
	HeroShip(void);
	~HeroShip(void);
	void Init(Vector2 position);
	void Draw(Core::Graphics graphics);
	void Update(Vector2 accelerationVector,float dt);
	void Update(float dt);
	void Fire();
	FountainParticleEffect* GetFountainParticleEffect();
	void UpdateFountain();
};