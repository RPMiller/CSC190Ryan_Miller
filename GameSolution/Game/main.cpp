#include "Engine.h"
#include "Core.h"
#include "HeroShip.h"
#include "BoundsOption.h"
#include "WrapOption.h"
#include "ArbitraryBounceOption.h"
#include "Lerper.h"
#include "Utilities.h"
#include "RecursiveRotation.h"

using Core::Input;

const float SCREEN_WIDTH = 1024;
const float SCREEN_HEIGHT = 768;
HeroShip* ship;
GameObject* lerp;
BoundsOption* boundsOption;
WrapOption wrap;
BounceOption bounce;
ArbitraryBounceOption arb;
bool arbOn = false;
Utilities util;
char* boundsType = "wrap";
RecursiveRotation* recurse;


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
	recurse = new RecursiveRotation(4,30,Vector2(120,350));
	Core::Init("Game Demo",(int)SCREEN_WIDTH,(int)SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
}

bool Update(float dt)
{
	const float BASE_SPEED = 6;
	const float ROTATE_SPEED = .1f;
	float y = 0;
	float rotate = 0;
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
		rotate = ROTATE_SPEED;
	}
	if(Input::IsPressed('D') || Input::IsPressed(Input::KEY_RIGHT))
	{
		rotate = -ROTATE_SPEED;
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
	if(Input::IsPressed(32))
	{
		ship->Fire();
	}
	lerp->Update(Vector2());
	boundsOption->CheckBounds(ship,SCREEN_HEIGHT,SCREEN_WIDTH);
	ship->Rotate(rotate);
	ship->Update(Vector2(0,y) * dt);
	return Input::IsPressed(Input::KEY_ESCAPE);
}

void Draw(Core::Graphics& graphics)
{
	lerp->Draw(graphics);
	ship->Draw(graphics);
	recurse->Rotate(.05f,graphics);
	graphics.DrawString(0,0,"1 : Wrap");
	graphics.DrawString(0,10,"2 : Bounce");
	graphics.DrawString(0,20,"3 : Arbitrary Bounce");
	graphics.DrawString(0,30,"W/Up : Increase Velocity In Forward Direction");
	graphics.DrawString(0,40,"S/Down : Increase Velocity In Backward Direction");
	graphics.DrawString(0,50,"A/Left : Rotate Left");
	graphics.DrawString(0,60,"D/Right : Rotate Right");
	graphics.DrawString(0,70,"Space : Fire Missile");
	graphics.DrawString(0,80,"Ship Position : ");
	util.DrawValue(graphics,100,80,ship->GetPosition());
	graphics.DrawString(0,90,"Ship Velocity : ");
	util.DrawValue(graphics,100,90,ship->GetVelocity());
	graphics.DrawString(0,100,"Bounds Option : ");
	graphics.DrawString(100,100,boundsType);
	util.DrawValue(graphics,0,110,ship->GetTranslationMatrix());
	if(arbOn)
	{
		graphics.DrawLine(SCREEN_WIDTH/2,SCREEN_HEIGHT,SCREEN_WIDTH,SCREEN_HEIGHT/2);
		graphics.DrawLine(SCREEN_WIDTH,SCREEN_HEIGHT/2,SCREEN_WIDTH/2,0);
		graphics.DrawLine(SCREEN_WIDTH/2,0,0,SCREEN_HEIGHT/2);
		graphics.DrawLine(0,SCREEN_HEIGHT/2,SCREEN_WIDTH/2,SCREEN_HEIGHT);
	}
}