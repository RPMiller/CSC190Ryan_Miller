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
#include "MyMathUtil.h"
#include "Vector3.h"
#include "Matrix4.h"
#include "ScreenConstants.h"
#include "IntroScreen.h"
#include "DebugMemory.h"

#ifdef LOG_ON
#define ASSERT(expr, ...)  do { const char* msg = #expr##" "##__VA_ARGS__; if (!(expr)) {LOG(Severe, msg ); END_LOG DebugBreak(); exit(1);}}while(0);
#else
#define ASSERT(expr, ...)
#endif

using Core::Input;

Screen* game;
Utilities util;
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
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF 
 );

	//_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
#pragma warning(disable : 4127)
	ASSERT(false,"test");
#pragma warning(default : 4127)
	game = new IntroScreen();
	game->SetScore(0);
	LOG(Info,"Intro Started");
	srand(time_t(NULL));
	Core::Init("Game Demo",(int)SCREEN_WIDTH,(int)SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
}

bool Update(float dt)
{
	if(game->Update(dt))
	{
		Screen* nextScreen = game->GetNextScreen();
		game->Destroy();
		delete game;
		game = nextScreen;
		LOG(Info,"Screen Changed");
	}
	bool shouldExit = Input::IsPressed(Input::KEY_ESCAPE);
	if(shouldExit)
	{
		game->Destroy();
		delete game;
		game = 0;
		LOG(Info,"Exiting");
		END_LOG;
	}
	return shouldExit;

	//dt;
	//return false;
}

void Draw(Core::Graphics& graphics)
{
	//static float rads = 0;
	//rads += .1f;
	//float offset = 150;
	//float size = 200;
	//Vector3 center(0 + size/2,0 + size/2,0 + size/2);
	//Matrix4 rotation;
	//rotation.RotateAroundX(rads);
	////rotation.RotateAroundZ(rads);
	//Matrix4 translation;

	//translation = rotation * translation;

	//translation.Translate(offset,offset,0);
	//MyMathUtil util(center * translation);
	//Vector3 v1(0,0,0);
	//Vector3 v2(0 + size,0,0);
	//Vector3 v3(0 + size,0 + size,0);
	//Vector3 v4(0,0 + size,0);
	//Vector3 v5(0,0,0);
	//Vector3 v6(0,0,offset);
	//Vector3 v7(0 + size,0,offset);
	//Vector3 v8(0 + size,0 + size,offset);
	//Vector3 v9(0,0 + size,offset);
	//Vector3 v10(0,0,offset);

	//int vectorSize = 10;
	//Vector3 vectors[] = {v1,v2,v3,v4,v5,v6,v7,v8,v9,v10};

	//Vector2 previous = util.TranslateTo2D(vectors[0] * rotation);


	//for(int i = 0; i < vectorSize; i++)
	//{
	//	Vector3 test = vectors[i] * translation;
	//	Vector2 vector = util.TranslateTo2D(vectors[i] * translation);
	//	graphics.DrawLine(previous.x,previous.y + 100,vector.x,vector.y + 100);
	//	previous = vector;
	//}
	if(game != 0)
	{
		game->Draw(graphics);
	}

#ifdef DEBUG
	int yDrawPosition = (int)SCREEN_HEIGHT - 60;
	_CrtMemState state;
	_CrtMemCheckpoint(&state);
	graphics.DrawString(0,yDrawPosition,"LCounts : ");
	util.DrawValue(graphics,80,yDrawPosition,state.lCounts[_CLIENT_BLOCK]);
	yDrawPosition -= 15;
	graphics.DrawString(0,yDrawPosition,"LSizes : ");
	util.DrawValue(graphics,80,yDrawPosition,state.lSizes[_CLIENT_BLOCK]);
	yDrawPosition -= 15;
	graphics.DrawString(0,yDrawPosition,"LHighWaterCount : ");
	util.DrawValue(graphics,140,yDrawPosition,state.lHighWaterCount);
	yDrawPosition -= 15;
#endif
}