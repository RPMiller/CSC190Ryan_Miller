#include "EnemyShip.h"


EnemyShip::EnemyShip(void)
{
}


EnemyShip::~EnemyShip(void)
{
}

void EnemyShip::Init(Vector3 position)
{
	EnemyShip::position = position;
	color = Color(150,20,20);

	acceleration = 8000.0f;
	const float shipSize = 26;
	numberOfShapes = ShapeBuilder::CUBE_SHAPES_NUMBER;
	shapes = new Shape[ShapeBuilder::CUBE_SHAPES_NUMBER];

	ShapeBuilder::BuildCube(shipSize,shapes,0);
	height = GetHeight();
	width = GetWidth();
	depth = GetDepth();
}
	
ExplosionParticleEffect* EnemyShip::ExplodeObject()
{
	ExplosionParticleEffect* explosion = new ExplosionParticleEffect(100,position);
	explosion->Init();
	return explosion;
}
	
void EnemyShip::FollowHero(Vector3 heroPosition, float dt)
{
	const float BASE_SPEED = 1000;
	turret.SetBaseMissileVelocity(Normalized(heroPosition - position) * BASE_SPEED);
	turret.Fire();
	turret.Update(dt);

	Vector3 toHero = Normalized(heroPosition - position);
	velocity = Normalized(velocity + toHero) *( dt * acceleration);
	const float maxZ = -60;
	if(velocity.z < maxZ)
	{
		velocity.z = maxZ;
	}
	if(position.z < 0)
	{
		isAlive = false;
	}
	GameObject::Update(dt);
}

void EnemyShip::Draw(Core::Graphics graphics)
{
	turret.SetPosition(position);
	turret.Draw(graphics);
	GameObject::Draw(graphics);
}

Missile** EnemyShip::GetMissiles()
{
	return turret.GetMissiles();
}
	
int EnemyShip::GetTotalMissileNumber()
{
	return turret.GetNumberOfMissiles();
}