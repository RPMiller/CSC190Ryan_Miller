#include "Missile.h"


Missile::Missile(Vector3 position,Vector3 velocity,float ticks)
{
	ticksOfLife = ticks;
	SetPosition(position);
	SetVelocity(velocity);
	numberOfShapes = 1;
	shapes = new Shape[numberOfShapes];

	//const int NUMBER_LINES = 4;
	//const float MISSILE_SIZE = 3;
	//Vector3* lines = new Vector3[NUMBER_LINES];
	//Vector3 vertex1(0,-MISSILE_SIZE,0);
	//Vector3 vertex2(MISSILE_SIZE,MISSILE_SIZE,0);
	//Vector3 vertex3(-MISSILE_SIZE,MISSILE_SIZE,0);

	//lines[0] = vertex1;
	//lines[1] = vertex2;
	//lines[2] = vertex3;
	//lines[3] = vertex1;

	//Shape missile = Shape(lines,NUMBER_LINES,Matrix4());
	beam = new BeamShape(4);
	height = beam->GetHeight();
	width = beam->GetWidth();
	depth = beam->GetDepth();
	shapes[0] = *beam;
}


Missile::~Missile(void)
{
}

void Missile::Destroy()
{
	beam->Destroy();
	delete beam;
	delete [] shapes;
}

bool Missile::CheckDead()
{
	return ticksOfLife <= 0 && isAlive;
}

void Missile::Draw(Core::Graphics graphics)
{
	GameObject::Draw(graphics);
}

void Missile::Update(float dt)
{
	beam->Update(dt);
	GameObject::Update(dt);
	ticksOfLife -= dt;
}