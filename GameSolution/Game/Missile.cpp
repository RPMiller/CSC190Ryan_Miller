#include "Missile.h"


Missile::Missile(Vector2 position,Vector2 velocity)
{
	ticksOfLife = 7;
	SetPosition(position);
	SetVelocity(velocity);
	numberOfShapes = 1;
	shapes = new Shape[numberOfShapes];

	const int NUMBER_LINES = 4;
	const float MISSILE_SIZE = 3;
	Vector2* lines = new Vector2[NUMBER_LINES];
	Vector2 vertex1(0,-MISSILE_SIZE);
	Vector2 vertex2(MISSILE_SIZE,MISSILE_SIZE);
	Vector2 vertex3(-MISSILE_SIZE,MISSILE_SIZE);

	lines[0] = vertex1;
	lines[1] = vertex2;
	lines[2] = vertex3;
	lines[3] = vertex1;

	Shape missile = Shape(lines,NUMBER_LINES,Matrix3());
	shapes[0] = missile;
	height = missile.GetHeight();
	width = missile.GetWidth();
}


Missile::~Missile(void)
{
}

bool Missile::CheckDead()
{
	return ticksOfLife <= 0;
}

void Missile::Draw(Core::Graphics graphics)
{
	GameObject::Draw(graphics);
}

void Missile::Update(float dt)
{
	GameObject::Update(dt);
	ticksOfLife -= dt;
}