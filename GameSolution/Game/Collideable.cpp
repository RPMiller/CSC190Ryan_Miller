#include "Collideable.h"


Collideable::Collideable(void)
{
}


Collideable::~Collideable(void)
{
}

bool Collideable::CheckCollision(Missile* missile)
{
	Vector2 distance = Vector2(position.x,position.y) - Vector2(missile->GetPosition().x,missile->GetPosition().y);
	float misslieRadius = (missile->GetHeight() + missile->GetWidth()) / 2;
	float enemyRadius = (GetHeight() + GetWidth());
	float enemyDepthRadius = GetDepth() / 2;
	float missileDepthRadius = missile->GetDepth() / 2;
	bool collided = Length(distance) <= (misslieRadius + enemyRadius) && abs(position.z - missile->GetPosition().z) <= enemyDepthRadius + missileDepthRadius;

	if(collided)
	{
    	if(missile->isAlive)
		{
			missile->isAlive = false;
			health--;
			if(health <= 0)
			{
				isAlive = false;
				
			}
		}
	}
	return collided;
}

float Collideable::GetHealth()
{
	return health;
}