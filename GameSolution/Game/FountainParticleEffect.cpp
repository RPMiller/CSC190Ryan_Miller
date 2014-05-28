#include "FountainParticleEffect.h"


FountainParticleEffect::FountainParticleEffect(int numParticles,Vector2 origin) : ParticleEffect(numParticles,origin)
{
	range = .5;
	direction = Vector2(0,1);
}


FountainParticleEffect::~FountainParticleEffect(void)
{
}

void FountainParticleEffect::Init()
{
	for(int i = 0; i < numberOfParticles; i++)
	{
		InitializeParticle(i);
	}
}

void FountainParticleEffect::Update(float dt)
{
	for(int i = 0; i < numberOfParticles; i++)
	{
		particles[i].Update(dt);
		particles[i].UpdateLifeSpan(dt);
		if(!particles[i].isAlive)
		{
			InitializeParticle(i);
		}
	}
}
	
void FountainParticleEffect::Draw(Core::Graphics graphics)
{
	for(int i = 0; i < numberOfParticles; i++)
	{
		particles[i].Draw(graphics);
	}
}

void FountainParticleEffect::InitializeParticle(int index)
{
	particles[index] = DotParticle();
	particles[index].SetPosition(origin);
	particles[index].SetVelocity(randomGenerator.GenerateRandomVector(direction.x - range,direction.x + range,direction.y - range,direction.y + range) * randomGenerator.GenerateRandomFloat(20,60));
	particles[index].SetLifeSpan(randomGenerator.GenerateRandomFloat(1,3));
}

void FountainParticleEffect::SetRange(float range)
{
	FountainParticleEffect::range = range;
}

void FountainParticleEffect::SetDirection(Vector2 direction)
{
	FountainParticleEffect::direction = direction;
}