#include "Engine.h"
#include "Core.h"
#include "HeroShip.h"
#include "BoundsOption.h"
#include "WrapOption.h"
#include "ArbitraryBounceOption.h"
#include "Lerper.h"
#include "Utilities.h"

using Core::Input;

const float SCREEN_WIDTH = 1024;
const float SCREEN_HEIGHT = 768;
GameObject* ship;
GameObject* lerp;
BoundsOption* boundsOption;
WrapOption wrap;
BounceOption bounce;
ArbitraryBounceOption arb;
bool arbOn = false;
Utilities util;
char* boundsType = "wrap";


bool Update(float dt);
void Draw(Core::Graphics& graphics);

int main()
{
	boundsOption = &wrap;
	HeroShip heroShip;
	heroShip.Init(Vector2(SCREEN_WIDTH/2,SCREEN_HEIGHT/2));
	ship = &heroShip;
	Lerper lerper;
	lerper.Init(Vector2(SCREEN_WIDTH/2,SCREEN_HEIGHT/2));
	lerp = &lerper;
	Core::Init("Game Demo",(int)SCREEN_WIDTH,(int)SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
}

bool Update(float dt)
{
	const float BASE_SPEED = 6;
	float x = 0;
	float y = 0;
	if(Input::IsPressed('W') || Input::IsPressed(Input::KEY_UP))
	{
		y = -BASE_SPEED;
	}
	if(Input::IsPressed('S') || Input::IsPressed(Input::KEY_DOWN))
	{
		y = BASE_SPEED;
	}
	if(Input::IsPressed('A') || Input::IsPressed(Input::KEY_LEFT))
	{
		x = -BASE_SPEED;
	}
	if(Input::IsPressed('D') || Input::IsPressed(Input::KEY_RIGHT))
	{
		x = BASE_SPEED;
	}
	if(Input::IsPressed('1'))
	{
		boundsOption = &wrap;
		arbOn = false;
		boundsType = "wrap";
	}
	if(Input::IsPressed('2'))
	{
		boundsOption = &bounce;
		arbOn = false;
		boundsType = "bounce";
	}
	if(Input::IsPressed('3'))
	{
		arbOn = true;
		boundsOption = &arb;
		boundsType = "arbitrary bounce";
	}
	lerp->Update(Vector2());
	boundsOption->CheckBounds(ship,SCREEN_HEIGHT,SCREEN_WIDTH);
	ship->Update(Vector2(x,y) * dt);
	return Input::IsPressed(Input::KEY_ESCAPE);
}

void Draw(Core::Graphics& graphics)
{
	lerp->Draw(graphics);
	ship->Draw(graphics);
	graphics.DrawString(0,0,"1 : Wrap");
	graphics.DrawString(0,10,"2 : Bounce");
	graphics.DrawString(0,20,"3 : Arbitrary Bounce");
	graphics.DrawString(0,30,"Ship Position : ");
	util.DrawValue(graphics,100,30,ship->GetPosition());
	graphics.DrawString(0,40,"Ship Velocity : ");
	util.DrawValue(graphics,100,40,ship->GetVelocity());
	graphics.DrawString(0,50,"Bounds Option : ");
	graphics.DrawString(100,50,boundsType);
	if(arbOn)
	{
		graphics.DrawLine(SCREEN_WIDTH/2,SCREEN_HEIGHT,SCREEN_WIDTH,SCREEN_HEIGHT/2);
		graphics.DrawLine(SCREEN_WIDTH,SCREEN_HEIGHT/2,SCREEN_WIDTH/2,0);
		graphics.DrawLine(SCREEN_WIDTH/2,0,0,SCREEN_HEIGHT/2);
		graphics.DrawLine(0,SCREEN_HEIGHT/2,SCREEN_WIDTH/2,SCREEN_HEIGHT);
	}
}