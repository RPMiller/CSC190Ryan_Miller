#include "EnemyTurret.h"



EnemyTurret::EnemyTurret(void)
{
	color = Color(255,0,0);
	numberOfMissiles = 4;
	missiles = new Missile*[numberOfMissiles];
	for(int i = 0; i < numberOfMissiles;i++)
	{
		missiles[i] = 0;
	}
	reloadTimeLeft = 0.6f;
	baseReloadTime = reloadTimeLeft;
}


EnemyTurret::~EnemyTurret(void)
{
}