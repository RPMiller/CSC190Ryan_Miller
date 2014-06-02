#include "EnemyShip.h"


EnemyShip::EnemyShip(void)
{
}


EnemyShip::~EnemyShip(void)
{
}

void EnemyShip::Init(Vector2 position)
{
	EnemyShip::position = position;

	acceleration = 10.0f;
	const int numberOfShipLines = 8;
	const float shipSize = 26;
	Vector2* shipLines = new Vector2[numberOfShipLines];
	shipLines[0] = Vector2(0,-shipSize);
	shipLines[1] = Vector2(shipSize,0);
	shipLines[2] = Vector2(shipSize/2,0);
	shipLines[3] = Vector2(shipSize,shipSize);
	shipLines[4] = Vector2(-shipSize,shipSize);
	shipLines[5] = Vector2(-shipSize/2,0);
	shipLines[6] = Vector2(-shipSize,0);
	shipLines[7] = Vector2(0,-shipSize);
	Shape ship = Shape(shipLines,numberOfShipLines,translationMatrix);

	numberOfShapes = 1;
	height = ship.GetHeight();
	width = ship.GetWidth();
	shapes = new Shape[numberOfShapes];

	shapes[0] = ship;
}

bool EnemyShip::CheckCollision(Missile missile)
{
	Vector2 distance = position - missile.GetPosition();
	float misslieRadius = (missile.GetHeight() + missile.GetWidth()) / 2;
	float enemyRadius = (GetHeight() + GetWidth()) / 2;
	bool collided = Length(distance) <= misslieRadius + enemyRadius;
	if(collided)
	{
		isAlive = false;
	}
	return collided;
}
	
ExplosionParticleEffect* EnemyShip::ExplodeObject()
{
	ExplosionParticleEffect* explosion = new ExplosionParticleEffect(200,position);
	explosion->Init();
	return explosion;
}
	
void EnemyShip::FollowHero(Vector2 heroPosition, float dt)
{
	Vector2 toHero = Normalized(heroPosition - position);
	velocity = velocity + toHero *( dt * acceleration);
	GameObject::Update(dt);
}