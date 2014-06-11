#pragma once
#include "IntroScreen.h"


class DefeatScreen : public Screen
{
public:
	DefeatScreen(void);
	~DefeatScreen(void);
	bool Update(float dt);
	void Draw(Core::Graphics& graphics);
	Screen* GetNextScreen();
	virtual void Destroy();
};

