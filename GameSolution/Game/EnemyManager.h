#pragma once
#include "Missile.h"
#include <vector>
#include "EnemyShip.h"
#include "Timer.h"
#include "HeroShip.h"
#include "ParticleEffectManager.h"
#include "Boss.h"
#include "Logger.h"

class EnemyManager
{
	const int BOSS_WAVE;
	std::vector<Enemy*> enemies;
	float timeTillNextSpawn;
	Timer timer;
	int waveNumber;
	Boss* boss;
public:
	EnemyManager(void);
	~EnemyManager(void);
	bool UpdateEnemies(HeroShip* hero,ParticleEffectManager* effectManager,float dt);
	void DrawEnemies(Core::Graphics graphics);
	void SpawnWave();
	void BuildBasicEnemy(Vector3 position);
	void SpawnBoss();
	void Destroy();

	EnemyManager& operator=(const EnemyManager &tmp);
};

