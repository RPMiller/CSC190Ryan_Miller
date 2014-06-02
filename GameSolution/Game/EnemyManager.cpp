#include "EnemyManager.h"

EnemyManager::EnemyManager(void)
{
	timeTillNextSpawn = 15;
	EnemyShip* ship = new EnemyShip;
	ship->Init(Vector2(0,0));
	enemies.push_back(ship);
}


EnemyManager::~EnemyManager(void)
{
}

void EnemyManager::UpdateEnemies(HeroShip* hero,ParticleEffectManager* effectManager,float dt)
{
	timeTillNextSpawn -= timer.Interval();
	if(timeTillNextSpawn < 0)
	{
		EnemyShip* ship = new EnemyShip();
		ship->Init(Vector2(0,0));
		enemies.push_back(ship);
		timeTillNextSpawn = 15;
	}

	std::vector<EnemyShip*> enemiesToRemove;

	for(auto enemy : enemies)
	{
		enemy->FollowHero(hero->GetPosition(),dt);
		for(int missileIndex = 0; missileIndex < hero->turret.GetNumberOfMissiles();missileIndex++)
		{
			Missile* next = (hero->turret.GetMissiles()[missileIndex]);
			if(next != 0)
			{
				enemy->CheckCollision(*next);
			}
		}
		if(!enemy->isAlive)
		{
			effectManager->AddEffect(enemy->ExplodeObject());
			enemiesToRemove.push_back(enemy);
		}
	}

	for(EnemyShip* enemy : enemiesToRemove)
	{
		enemies.erase(std::find(enemies.begin(), enemies.end(), enemy));
		delete enemy;
	}
}

void EnemyManager::DrawEnemies(Core::Graphics graphics)
{
	for(auto enemy : enemies)
	{
		enemy->Draw(graphics);
	}
}