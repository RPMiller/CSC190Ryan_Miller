#pragma once
#include "IntroScreen.h"

class EndScreen : public Screen
{
public:
	EndScreen(void);
	~EndScreen(void);
	Screen* GetNextScreen();
};

