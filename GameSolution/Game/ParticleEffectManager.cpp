#include "ParticleEffectManager.h"


ParticleEffectManager::ParticleEffectManager(void)
{
}


ParticleEffectManager::~ParticleEffectManager(void)
{
}


void ParticleEffectManager::Update(float dt)
{
	std::vector<ParticleEffect*> effectsToRemove;
	for(ParticleEffect* effect : effects)
	{
		effect->Update(dt);
		if(!effect->isRunning())
		{
			effectsToRemove.push_back(effect);
		}
	}

	for(ParticleEffect* effect : effectsToRemove)
	{
		effects.erase(std::find(effects.begin(), effects.end(), effect));
	}
}
	
void ParticleEffectManager::Draw(Core::Graphics graphics)
{
	for(ParticleEffect* effect : effects)
	{
		effect->Draw(graphics);
	}
}

void ParticleEffectManager::AddEffect(ParticleEffect* effect)
{
	effects.push_back(effect);
}