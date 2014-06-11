#include "DefeatScreen.h"


DefeatScreen::DefeatScreen(void)
{
}


DefeatScreen::~DefeatScreen(void)
{
}

bool DefeatScreen::Update(float dt)
{
	Core::Input input;
	input;
	dt;
	return input.IsPressed('R');
}

void DefeatScreen::Draw(Core::Graphics& graphics)
{
	graphics.DrawString((int)SCREEN_WIDTH / 2 - 15, (int)SCREEN_HEIGHT / 2,"YOU LOST");
	graphics.DrawString((int)SCREEN_WIDTH / 2 - 190, (int)SCREEN_HEIGHT / 2 + 10,"Press R To Go Back To The Intro Screen Or Escape To Quit");
	graphics.DrawString((int)SCREEN_WIDTH / 2 - 22, (int)SCREEN_HEIGHT / 2 + 20,"Score: ");
	util.DrawValue(graphics,(int)SCREEN_WIDTH / 2 + 22, (int)SCREEN_HEIGHT / 2 + 20, score);
}

Screen* DefeatScreen::GetNextScreen()
{
	Screen* intro = new IntroScreen();
	intro->SetScore(score);
	return intro;
}