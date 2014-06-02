#define DEBUG

#include "Engine.h"
#include "Core.h"
#include "HeroShip.h"
#include "BoundsOption.h"
#include "WrapOption.h"
#include "ArbitraryBounceOption.h"
#include "Lerper.h"
#include "Utilities.h"
#include "RecursiveRotation.h"
#include "Game.h"

using Core::Input;

Game* game;
//const float SCREEN_WIDTH = 1024;
//const float SCREEN_HEIGHT = 768;
//HeroShip* ship;
//GameObject* lerp;
//BoundsOption* boundsOption;
//WrapOption wrap;
//BounceOption bounce;
//ArbitraryBounceOption arb;
//bool arbOn = false;
//Utilities util;
//char* boundsType = "wrap";
//RecursiveRotation* recurse;


bool Update(float dt);
void Draw(Core::Graphics& graphics);

int main()
{
	Game temp(1024,726);
	game = &temp;
	srand(time_t(NULL));
	Core::Init("Game Demo",(int)game->GetWidth(),(int)game->GetHeight());
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
}

bool Update(float dt)
{
	game->Update(dt);
	return Input::IsPressed(Input::KEY_ESCAPE);
}

void Draw(Core::Graphics& graphics)
{
	game->Draw(graphics);
}