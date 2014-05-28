#include "Particle.h"


Particle::Particle(void)
{
}


Particle::~Particle(void)
{
}

void Particle::UpdateLifeSpan(float dt)
{
	lifeSpan -= dt;
	isAlive = lifeSpan >0;
}

void Particle::SetLifeSpan(float life)
{
	lifeSpan = life;
	isAlive = lifeSpan >0;
}