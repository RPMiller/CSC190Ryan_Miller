#pragma once
#include "Missile.h"
#include <vector>
#include "EnemyShip.h"
#include "Timer.h"
#include "HeroShip.h"
#include "ParticleEffectManager.h"

class EnemyManager
{
	std::vector<EnemyShip*> enemies;
	float timeTillNextSpawn;
	Timer timer;
public:
	EnemyManager(void);
	~EnemyManager(void);
	void UpdateEnemies(HeroShip* hero,ParticleEffectManager* effectManager,float dt);
	void DrawEnemies(Core::Graphics graphics);
};

