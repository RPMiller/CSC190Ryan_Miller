#pragma once
#include "ParticleEffect.h"
#include "DotParticle.h"

class FountainParticleEffect : public ParticleEffect
{
	float range;
	Vector2 direction;
public:
	FountainParticleEffect(int numParticles,Vector2 origin);
	~FountainParticleEffect(void);
	void Update(float dt);
	void Draw(Core::Graphics graphics);
	void Init();
	void SetDirection(Vector2 direction);
	void InitializeParticle(int index);
	//should be between 0 and 1
	void SetRange(float range);
};

