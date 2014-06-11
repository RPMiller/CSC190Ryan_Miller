#pragma once
#include "Game.h"
#include "HeroShip.h"

class IntroScreen : public Screen
{
	GameObject* hero;
public:
	IntroScreen(void);
	~IntroScreen(void);

	bool Update(float dt);
	void Draw(Core::Graphics& graphics);
	Screen* GetNextScreen();
	virtual void Destroy();
};

