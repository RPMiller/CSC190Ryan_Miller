#pragma once
#include <vector>
#include "ParticleEffect.h"

class ParticleEffectManager
{
	std::vector<ParticleEffect*> effects;
public:
	ParticleEffectManager(void);
	~ParticleEffectManager(void);
	void Update(float dt);
	void Draw(Core::Graphics graphics);
	void AddEffect(ParticleEffect* effect);
	void Destroy();
};

