#pragma once
#include "particleeffect.h"
#include "RandomGenerator.h"
#include "SquareParticle.h"

class ExplosionParticleEffect :
	public ParticleEffect
{
public:
	ExplosionParticleEffect(int numParticles,Vector3 origin);
	~ExplosionParticleEffect(void);
	void Update(float dt);
	void Draw(Core::Graphics graphics);
	void Init();
};

