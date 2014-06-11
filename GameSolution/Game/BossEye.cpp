#include "BossEye.h"


BossEye::BossEye(void)
{
}


BossEye::~BossEye(void)
{
}

void BossEye::Destroy()
{
	turret.Destroy();
	GameObject::Destroy();
}

ExplosionParticleEffect* BossEye::ExplodeObject()
{
	return new ExplosionParticleEffect(300,position);
}

void BossEye::Update(float dt)
{
	turret.Update(dt);
}
	
void BossEye::Init(Vector3 position)
{
	health = 10;
	const float size = 100;
	const float eyeHeight = -100;
	color = Color(200,100,0);
	numberOfShapes = 1;
	shapes = new Shape[numberOfShapes];
	Vector3 top(0,-size / 2 + eyeHeight,0);
	Vector3 left(-size,size / 2 + eyeHeight,0);
	Vector3 right(size,size / 2 + eyeHeight,0);
	int shapeIndex = 0;
	ShapeBuilder::BuildTriangle(top,left,right,shapes,shapeIndex);
	BossEye::position = position;
	height = GetHeight();
	width = GetWidth();
	depth = GetDepth();
}

void BossEye::Fire(Vector3 heroShipPosition)
{
	if(isAlive)
	{
		const float BASE_SPEED = 400;
		turret.SetBaseMissileVelocity(Normalized(heroShipPosition - position) * BASE_SPEED);
		turret.Fire();
	}
}

void BossEye::Draw(Core::Graphics graphics)
{
	turret.Draw(graphics);
	GameObject::Draw(graphics);
}

void BossEye::SetPosition(Vector3 position)
{
	turret.SetPosition(position);
	GameObject::SetPosition(position);
}

Turret BossEye::GetTurret()
{
	return turret;
}