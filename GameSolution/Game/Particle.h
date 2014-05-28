#pragma once
#include "GameObject.h"
#include "Color.h"

class Particle : public GameObject
{
protected :
	float lifeSpan;
public:
	Color color;
	Particle(void);
	~Particle(void);
	void UpdateLifeSpan(float dt);
	void SetLifeSpan(float life);
};

