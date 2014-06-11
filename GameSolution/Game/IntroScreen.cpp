#include "IntroScreen.h"


IntroScreen::IntroScreen(void)
{
	hero = new HeroShip();
	hero->Init(Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 40, 20));
}


IntroScreen::~IntroScreen(void)
{
}

bool IntroScreen::Update(float dt)
{
	Core::Input input;
	const float roatationRate = -10.5f * dt;
	hero->RotateAroundZ(roatationRate);
	input;
	return input.IsPressed('F');
}

void IntroScreen::Draw(Core::Graphics& graphics)
{
	graphics.DrawString((int)SCREEN_WIDTH / 2 - 40,(int)SCREEN_HEIGHT / 5, "Press F To Begin");
	graphics.DrawString((int)SCREEN_WIDTH / 2 - 42,(int)SCREEN_HEIGHT / 5 + 10, "Press ESC To Quit");
	graphics.DrawString((int)SCREEN_WIDTH / 2 - 30, 0,"High Score: ");
	util.DrawValue(graphics,(int)SCREEN_WIDTH / 2 + 55, 0, score);
	hero->Draw(graphics);
}

Screen* IntroScreen::GetNextScreen()
{
	hero->Destroy();
	delete hero;
	return new Game();
}