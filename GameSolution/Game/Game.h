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
#include "Logger.h"
#include "Screen.h"
#include "VictoryScreen.h"
#include "DefeatScreen.h"
#include "ScreenConstants.h"
#include "WallOption.h"

#ifdef DEBUG
#include "Profiler.h"
#endif

#include "Timer.h"

using Core::Input;
class Game : public Screen
{
	const float POINTS_PER_HEALTH;
	HeroShip* ship;
	//GameObject* lerp;
	BoundsOption* boundsOption;
	/*WrapOption wrap;
	BounceOption bounce;
	ArbitraryBounceOption arb;*/
	WallOption wallOption;
	bool arbOn;
	Utilities util;
	char* boundsType;
	//RecursiveRotation* recurse;
	ParticleEffectManager effectManager;
	EnemyManager enemyManger;
	float score;

#ifdef DEBUG
	Profiler profiler;
#endif
	Timer timer;
	Timer drawTimer;
	void DrawInfo(Core::Graphics graphics,float framesPerSecond,float secondsPerFrame);

public:
	Game();
	~Game(void);
	void Draw(Core::Graphics& graphics);
	bool Update(float dt);
	Screen* GetNextScreen();
	float GetHeight();
	float GetWidth();
	virtual void Destroy();




	Game& operator=(const Game &tmp);
};

