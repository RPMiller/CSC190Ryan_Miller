#pragma once
#include "GameObject.h"
#include "Turret.h"
#include "Enemy.h"
#include "BossTurret.h"

class BossEye : public Collideable
{
	BossTurret turret;	
public:
	BossEye(void);
	~BossEye(void);
	ExplosionParticleEffect* ExplodeObject();
	void Init(Vector3 position);
	void Update(float dt);
	void Fire(Vector3 heroShipPosition);
	void Draw(Core::Graphics graphics);
	void SetPosition(Vector3 position);
	Turret GetTurret();
};

