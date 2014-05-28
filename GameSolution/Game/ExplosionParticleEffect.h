#pragma once
#include "particleeffect.h"
#include "RandomGenerator.h"
#include "SquareParticle.h"

class ExplosionParticleEffect :
	public ParticleEffect
{
public:
	ExplosionParticleEffect(int numParticles,Vector2 origin);
	~ExplosionParticleEffect(void);
	void Update(float dt);
	void Draw(Core::Graphics graphics);
	void Init();
};

