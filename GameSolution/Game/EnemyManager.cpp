#include "EnemyManager.h"

EnemyManager::EnemyManager(void) : BOSS_WAVE(4)
{
	timeTillNextSpawn = 15;
	waveNumber = 0;
}


EnemyManager::~EnemyManager(void)
{
}

bool EnemyManager::UpdateEnemies(HeroShip* hero,ParticleEffectManager* effectManager,float dt)
{
	if(hero->isAlive)
	{
		timeTillNextSpawn -= timer.Interval();
		if(timeTillNextSpawn < 0)
		{
			if(waveNumber < BOSS_WAVE)
			{
				SpawnWave();
				waveNumber++;
			}
			else if(waveNumber == BOSS_WAVE)
			{
				SpawnBoss();
				waveNumber++;
			}
		}

		std::vector<Enemy*> enemiesToRemove;

		for(auto enemy : enemies)
		{
			enemy->FollowHero(hero->GetPosition(),dt);
		
			Missile** missiles = enemy->GetMissiles();
			for(int i = 0; i < enemy->GetTotalMissileNumber(); i++)
			{
				Missile* next = (missiles[i]);
				if(next != 0)
				{
					hero->CheckCollision(missiles[i]);
					if(!hero->isAlive)
					{
						effectManager->AddEffect(hero->ExplodeObject());
					}
				}
			}

			for(int missileIndex = 0; missileIndex < hero->turret.GetNumberOfMissiles();missileIndex++)
			{
				Missile* next = (hero->turret.GetMissiles()[missileIndex]);
				if(next != 0)
				{
					enemy->CheckCollision(next);
				}
			}
			if(!enemy->isAlive)
			{
				effectManager->AddEffect(enemy->ExplodeObject());
				enemiesToRemove.push_back(enemy);
			}
		}

		for(Enemy* enemy : enemiesToRemove)
		{
			enemies.erase(std::find(enemies.begin(), enemies.end(), enemy));
			delete enemy;
		}
	}

	return !hero->isAlive || !(waveNumber <= BOSS_WAVE || boss->isAlive);
}

void EnemyManager::DrawEnemies(Core::Graphics graphics)
{
	for(auto enemy : enemies)
	{
		enemy->Draw(graphics);
	}
}

void EnemyManager::SpawnWave()
{
	const float ENEMY_DEPTH = 250.0f;
	BuildBasicEnemy(Vector3(SCREEN_WIDTH / 2,SCREEN_HEIGHT/2,ENEMY_DEPTH));
	timeTillNextSpawn = 6;
}

void EnemyManager::BuildBasicEnemy(Vector3 position)
{
	Enemy* ship = new EnemyShip();
	ship->Init(position);
	enemies.push_back(ship);
}

void EnemyManager::SpawnBoss()
{
	boss = new Boss();
	boss->Init(Vector3(SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,300));
	enemies.push_back(boss);
}