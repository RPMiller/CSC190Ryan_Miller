#pragma once
#include "gameobject.h"
#include "ExplosionParticleEffect.h"
#include "Missile.h"

class EnemyShip :
	public GameObject
{
public:
	EnemyShip(void);
	~EnemyShip(void);
	bool CheckCollision(Missile missile);
	ExplosionParticleEffect* ExplodeObject();
	void FollowHero(Vector2 heroPosition, float dt);
	void Init(Vector2 position);
};

