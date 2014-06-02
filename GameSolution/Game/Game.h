#pragma once

#include "Engine.h"
#include "Core.h"
#include "HeroShip.h"
#include "BoundsOption.h"
#include "WrapOption.h"
#include "ArbitraryBounceOption.h"
#include "Lerper.h"
#include "Utilities.h"
#include "RecursiveRotation.h"
#include "ParticleEffectManager.h"
#include "ExplosionParticleEffect.h"
#include "FountainParticleEffect.h"
#include "EnemyManager.h"

#ifdef DEBUG
#include "Profiler.h"
#endif

#include "Timer.h"

using Core::Input;
class Game
{
	const float SCREEN_WIDTH;
	const float SCREEN_HEIGHT;
	HeroShip* ship;
	GameObject* lerp;
	BoundsOption* boundsOption;
	WrapOption wrap;
	BounceOption bounce;
	ArbitraryBounceOption arb;
	bool arbOn;
	Utilities util;
	char* boundsType;
	RecursiveRotation* recurse;
	ParticleEffectManager effectManager;
	EnemyManager enemyManger;

#ifdef DEBUG
	Profiler profiler;
#endif
	Timer timer;
	Timer drawTimer;

public:
	Game(float ScreenWidth,float ScreenHeight);
	~Game(void);
	void Draw(Core::Graphics& graphics);
	void Update(float dt);
	float GetHeight();
	float GetWidth();
	Game& operator=(const Game &tmp);
};

