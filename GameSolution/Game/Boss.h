#pragma once
#include "enemy.h"
#include "BossEye.h"

class Boss :
	public Enemy
{
	BossEye leftEye,rightEye;
public:
	Boss(void);
	~Boss(void);
	bool CheckCollision(Missile* missile);
	ExplosionParticleEffect* ExplodeObject();
	void Init(Vector3 position);
	void Draw(Core::Graphics graphics);
	void FollowHero(Vector3 heroPosition,float dt);
	Missile** GetMissiles();
	int GetTotalMissileNumber();
};

