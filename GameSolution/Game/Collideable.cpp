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
	float enemyRadius = (GetHeight() + GetWidth()) / 2;
	float enemyDepthRadius = GetDepth() / 4;
	float missileDepthRadius = missile->GetDepth() / 2;
	bool collided = Length(distance) <= (misslieRadius + enemyRadius) && abs(position.z - missile->GetPosition().z) <= enemyDepthRadius + missileDepthRadius;

	if(collided)
	{
       	if(missile->isAlive)
		{
			missile->isAlive = false;
			health--;
			damageBlinkTime = damageBlinkMaxTime;
			color = damageColor;
			if(health <= 0)
			{
				isAlive = false;
				
			}
		}
	}
	return collided;
}

void Collideable::Update(Vector3 accelerationVector,float dt)
{
	GameObject::Update(accelerationVector, dt);
	if(damageBlinkTime < 0)
	{
		color = normalColor;
		damageBlinkTime = 0;
	}
	else if( damageBlinkTime > 0)
	{
		damageBlinkTime -= dt;
	}
}
	
void Collideable::Update(float dt)
{
	GameObject::Update(dt);
	if(damageBlinkTime < 0)
	{
		color = normalColor;
		damageBlinkTime = 0;
	}
	else if( damageBlinkTime > 0)
	{
		damageBlinkTime -= dt;
	}
}

float Collideable::GetHealth()
{
	return health;
}