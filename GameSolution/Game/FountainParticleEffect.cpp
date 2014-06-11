#include "FountainParticleEffect.h"


FountainParticleEffect::FountainParticleEffect(int numParticles,Vector3 origin) : ParticleEffect(numParticles,origin)
{
	range = .5;
	direction = Vector3(0,1,0);
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
			particles[i].Destroy();
			InitializeParticle(i);
		}
	}
}
	
void FountainParticleEffect::Draw(Core::Graphics graphics)
{
		graphics.SetColor(RGB(color.red,color.green,color.blue));

	for(int i = 0; i < numberOfParticles; i++)
	{
		particles[i].Draw(graphics);
	}
}

void FountainParticleEffect::InitializeParticle(int index)
{
	DotParticle dotParticle;
	dotParticle.SetPosition(origin);
	Vector2 unitVector = randomGenerator.GenerateRandomVector(direction.x - range,direction.x + range,direction.y - range,direction.y + range);
	dotParticle.SetVelocity(Vector3(unitVector.x,unitVector.y,-2) * randomGenerator.GenerateRandomFloat(20,60));
	dotParticle.SetLifeSpan(randomGenerator.GenerateRandomFloat(1,3));
	particles[index] = dotParticle;
}

void FountainParticleEffect::SetRange(float range)
{
	FountainParticleEffect::range = range;
}

void FountainParticleEffect::SetDirection(Vector3 direction)
{
	FountainParticleEffect::direction = direction;
}