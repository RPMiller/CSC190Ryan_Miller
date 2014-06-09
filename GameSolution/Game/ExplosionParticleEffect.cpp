#include "ExplosionParticleEffect.h"

ExplosionParticleEffect::ExplosionParticleEffect(int numParticles,Vector3 origin) : ParticleEffect(numParticles,origin)
{

}

ExplosionParticleEffect::~ExplosionParticleEffect(void)
{
}

void ExplosionParticleEffect::Init()
{
	for(int i = 0; i < numberOfParticles; i++)
	{
		particles[i] = SquareParticle();
		particles[i].SetPosition(origin);
		Vector2 unitVector = randomGenerator.GenerateRandomUnitVector();
		particles[i].SetVelocity(Vector3(unitVector.x,unitVector.y,1) * randomGenerator.GenerateRandomFloat(20,60));
		particles[i].SetLifeSpan(randomGenerator.GenerateRandomFloat(1,8));
	}
}

void ExplosionParticleEffect::Update(float dt)
{
	for(int i = 0; i < numberOfParticles; i++)
	{
		particles[i].Update(dt);
		particles[i].UpdateLifeSpan(dt);
	}
}
	
void ExplosionParticleEffect::Draw(Core::Graphics graphics)
{
	for(int i = 0; i < numberOfParticles; i++)
	{
		particles[i].Draw(graphics);
	}
}