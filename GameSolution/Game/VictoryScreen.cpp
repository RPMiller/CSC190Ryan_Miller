#include "VictoryScreen.h"


VictoryScreen::VictoryScreen(void)
{
}


VictoryScreen::~VictoryScreen(void)
{
}

bool VictoryScreen::Update(float dt)
{
	Core::Input input;
	input;
	dt;
	return input.IsPressed('R');
}

void VictoryScreen::Draw(Core::Graphics& graphics)
{
	graphics.DrawString((int)SCREEN_WIDTH / 2 - 15, (int)SCREEN_HEIGHT / 2,"YOU WON");
	graphics.DrawString((int)SCREEN_WIDTH / 2 - 190, (int)SCREEN_HEIGHT / 2 + 10,"Press R To Go Back To The Intro Screen Or Escape To Quit");
	graphics.DrawString((int)SCREEN_WIDTH / 2 - 22, (int)SCREEN_HEIGHT / 2 + 20,"Score: ");
	util.DrawValue(graphics,(int)SCREEN_WIDTH / 2 + 22, (int)SCREEN_HEIGHT / 2 + 20, score);
}

Screen* VictoryScreen::GetNextScreen()
{
	return new IntroScreen();
}