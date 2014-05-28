#include "HeroShip.h"

HeroShip::HeroShip()
{

}

HeroShip::~HeroShip(void)
{
	//delete shapes;
}

void HeroShip::Init(Vector2 position)
{
	HeroShip::position = position;
	fountain = new FountainParticleEffect(500,Vector2(position.x,position.y + 17));
	fountain->Init();

	acceleration = 2;
	const int numberOfShipLines = 7;
	const float shipSize = 32;
	Vector2* shipLines = new Vector2[numberOfShipLines];
	shipLines[0] = Vector2(0,-shipSize);
	shipLines[1] = Vector2(shipSize,0);
	shipLines[2] = Vector2(shipSize,shipSize);
	shipLines[3] = Vector2(0,shipSize / 2);
	shipLines[4] = Vector2(-shipSize,shipSize);
	shipLines[5] = Vector2(-shipSize,0);
	shipLines[6] = Vector2(0,-shipSize);
	Shape ship = Shape(shipLines,numberOfShipLines,translationMatrix);
	turret.TransformToBasicTurret();

	numberOfShapes = 1;
	height = ship.GetHeight();
	width = ship.GetWidth();
	shapes = new Shape[numberOfShapes];

	shapes[0] = ship;
}

void HeroShip::Draw(Core::Graphics graphics)
{
	GameObject::Draw(graphics);
	turret.SetPosition(position);
	turret.Draw(graphics);
}

void HeroShip::Update(Vector2 accelerationVector,float dt)
{
	GameObject::Update(accelerationVector,dt);
	turret.Update(dt);
	UpdateFountain();
}
	
void HeroShip::Update(float dt)
{
	GameObject::Update(dt);
	turret.Update(dt);
	UpdateFountain();
}

void HeroShip::Fire()
{
	turret.Fire();
}

FountainParticleEffect* HeroShip::GetFountainParticleEffect()
{
	return fountain;
}

void HeroShip::UpdateFountain()
{
	Vector2 down(0,1);
	Vector2 fountainOffSet(0 , 17);
	Vector2 fountainOrigin(Vector2(position.x,position.y));
	Matrix3 rotation;
	rotation.Rotate(radsRotated);
	fountain->SetOrigin(fountainOffSet * rotation + fountainOrigin);
	fountain->SetDirection(down * rotation);
}