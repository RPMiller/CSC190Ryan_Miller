#pragma once
#include "IntroScreen.h"
class VictoryScreen : public Screen
{
public:
	VictoryScreen(void);
	~VictoryScreen(void);
	bool Update(float dt);
	void Draw(Core::Graphics& graphics);
	Screen* GetNextScreen();
	virtual void Destroy();
};

