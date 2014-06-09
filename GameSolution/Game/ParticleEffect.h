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
	Vector3 origin;
	int numberOfParticles;
	Color color;
public:
	ParticleEffect(int numParticles,Vector3 origin);
	~ParticleEffect(void);
	bool isRunning();
	void SetOrigin(Vector3 nextOrigin);
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(Core::Graphics graphics) = 0;
	void SetColor(Color color);
};

