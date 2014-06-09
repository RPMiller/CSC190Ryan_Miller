#pragma once
#include "gameobject.h"
#include "ExplosionParticleEffect.h"
#include "Missile.h"
#include "Enemy.h"
#include "EnemyTurret.h"

class EnemyShip : public Enemy
{
	EnemyTurret turret;
public:
	EnemyShip(void);
	~EnemyShip(void);
	ExplosionParticleEffect* ExplodeObject();
	void Init(Vector3 position);
	void FollowHero(Vector3 heroPosition, float dt);
	void Draw(Core::Graphics graphics);
	Missile** GetMissiles();
	int GetTotalMissileNumber();
};

