#include "Boss.h"


Boss::Boss(void)
{

}


Boss::~Boss(void)
{
}

bool Boss::CheckCollision(Missile* missile)
{
	if(leftEye.isAlive)
	{
		if(leftEye.CheckCollision(missile))
		{
 			missile->isAlive = false;
		}
	}
	if(rightEye.CheckCollision(missile))
	{
   		missile->isAlive = false;
	}
	if(!rightEye.isAlive)
	{
		rightEye.SetColor(Color(255,255,255));
	}
	if(!leftEye.isAlive)
	{
		leftEye.SetColor(Color(255,255,255));
	}
	isAlive = leftEye.isAlive || rightEye.isAlive;
	return isAlive;
}
	
ExplosionParticleEffect* Boss::ExplodeObject()
{
	return new ExplosionParticleEffect(500,position);
}
	
void Boss::Init(Vector3 position)
{
	Boss::position = position;
	leftEye.Init(position);
	rightEye.Init(position);
	health = 1000000;
}

void Boss::FollowHero(Vector3 heroPosition,float dt)
{
	leftEye.Update(dt);
	rightEye.Update(dt);
	leftEye.Fire(heroPosition);
	rightEye.Fire(heroPosition);
	GameObject::Update(dt);
}

void Boss::Draw(Core::Graphics graphics)
{
	const int EYE_DISTANCE_WIDTH = 200;
	leftEye.SetPosition(Vector3(position.x - EYE_DISTANCE_WIDTH,position.y,position.z));
	leftEye.Draw(graphics);
	rightEye.SetPosition(Vector3(position.x + EYE_DISTANCE_WIDTH,position.y,position.z));
	rightEye.Draw(graphics);
	GameObject::Draw(graphics);
}

Missile** Boss::GetMissiles()
{
	int numberOfMissiles = leftEye.GetTurret().GetNumberOfMissiles() + rightEye.GetTurret().GetNumberOfMissiles();
	Missile** missiles = new Missile*[numberOfMissiles];
	Missile** leftMissiles = leftEye.GetTurret().GetMissiles();
	Missile** rightMissiles = rightEye.GetTurret().GetMissiles();
	for(int i = 0; i < leftEye.GetTurret().GetNumberOfMissiles(); i++)
	{
		missiles[i] = leftMissiles[i];
	}

	for(int i = leftEye.GetTurret().GetNumberOfMissiles(); i < leftEye.GetTurret().GetNumberOfMissiles() + rightEye.GetTurret().GetNumberOfMissiles();i++)
	{
		missiles[i] = rightMissiles[i - leftEye.GetTurret().GetNumberOfMissiles()];
	}
	return missiles;
}

int Boss::GetTotalMissileNumber()
{
	return leftEye.GetTurret().GetNumberOfMissiles() + rightEye.GetTurret().GetNumberOfMissiles();
}