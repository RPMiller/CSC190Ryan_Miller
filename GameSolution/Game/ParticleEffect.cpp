#include "ParticleEffect.h"


ParticleEffect::ParticleEffect(int numParticles,Vector3 origin) : origin(origin) , numberOfParticles(numParticles)
{
	particles = new Particle[numParticles];
}

ParticleEffect::~ParticleEffect(void)
{
}

void ParticleEffect::SetOrigin(Vector3 nextOrigin)
{
	origin = nextOrigin;
}

bool ParticleEffect::isRunning()
{
	bool isRunning = false;

	for(int i = 0; i < numberOfParticles && !isRunning; i++)
	{
		isRunning = particles[i].isAlive;
	}

	return isRunning;
}

void ParticleEffect::SetColor(Color color)
{
	ParticleEffect::color = color;

}