#pragma once
#include "Core.h"
#include "Particle.h"
#include "RandomGenerator.h"
#include "Vector2.h"

class ParticleEffect
{
protected :
	Particle* particles;
	RandomGenerator randomGenerator;
	Vector2 origin;
	int numberOfParticles;
public:
	ParticleEffect(int numParticles,Vector2 origin);
	~ParticleEffect(void);
	bool isRunning();
	void SetOrigin(Vector2 nextOrigin);
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(Core::Graphics graphics) = 0;
};

