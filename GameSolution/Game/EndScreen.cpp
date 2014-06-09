#include "EndScreen.h"


EndScreen::EndScreen(void)
{
}


EndScreen::~EndScreen(void)
{
}

Screen* EndScreen::GetNextScreen()
{
	return new IntroScreen();
}