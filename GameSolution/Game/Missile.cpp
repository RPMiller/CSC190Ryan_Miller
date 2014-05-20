#include "Missile.h"


Missile::Missile(Vector2 position,Vector2 velocity)
{
	ticksOfLife = 80;
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

	shapes[0] = Shape(lines,NUMBER_LINES,Matrix3());
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
	ticksOfLife--;
	GameObject::Draw(graphics);
}