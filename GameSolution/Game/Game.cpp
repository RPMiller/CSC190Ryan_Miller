#include "Game.h"

Game::Game()
{
	arbOn = false;
	boundsType = "bounce";
	boundsOption = &bounce;
	HeroShip* heroShip = new HeroShip();
	heroShip->Init(Vector3(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,0));
	ship = heroShip;
	//Lerper* lerper = new Lerper();
	//lerper->Init(Vector2(SCREEN_WIDTH/2,SCREEN_HEIGHT/2));
	//lerp = lerper;
	//recurse = new RecursiveRotation(4,30,Vector2(120,350));
	effectManager.AddEffect(ship->GetFountainParticleEffect());
	score = 1000;

	const int SIZE = 10;
	Vector3 fountainDirection(0,0,-50);
	float xPortionWidth = SCREEN_WIDTH / SIZE;
	float yPortionHeight = SCREEN_HEIGHT / SIZE;

	for(int i = 0; i < SIZE; i++)
	{

		for(int j = 0; j < SIZE; j++)
		{
			float x = xPortionWidth * j;
			float y = yPortionHeight * i;

			FountainParticleEffect* fountain = new FountainParticleEffect(5,Vector3(x,y,0));
			fountain->Init();
			fountain->SetRange(0);
			fountain->SetDirection(fountainDirection);
			fountain->SetColor(Color(255,255,0));
			effectManager.AddEffect(fountain);
		}
	}
}


Game::~Game(void)
{
}

bool Game::Update(float dt)
{
#ifdef DEBUG
	profiler.NewFrame();
#endif
	timer.Start();
	score -= dt;
	const float BASE_SPEED = 1;
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
	//lerp->Update(Vector2(),dt);
	boundsOption->CheckBounds(ship,SCREEN_HEIGHT,SCREEN_WIDTH);
	ship->RotateAroundZ(rotate);
	ship->Update(Vector3(0,y,0), dt);
	effectManager.Update(dt);
	bool isGameOver = enemyManger.UpdateEnemies(ship,&effectManager,dt);

#ifdef DEBUG
	profiler.AddEntry("Updated Full Game",timer.Stop());
#endif

	return isGameOver;
}

void Game::Draw(Core::Graphics& graphics)
{
	float secondsPerFrame = timer.Interval(); 
	float framesPerSecond = 1 / secondsPerFrame;
	float lerpTicks;
	float heroTicks;
	float recurseTicks;
	float effectTicks;

	timer.Start();
	drawTimer.Start();
	//lerp->Draw(graphics);
	lerpTicks = drawTimer.Stop();

	drawTimer.Start();
	ship->Draw(graphics);
	heroTicks= drawTimer.Stop();

	drawTimer.Start();
	//recurse->Rotate(.05f,graphics);
	recurseTicks= drawTimer.Stop();

	DrawInfo(graphics, framesPerSecond, secondsPerFrame);

	if(arbOn)
	{
		graphics.DrawLine(SCREEN_WIDTH/2,SCREEN_HEIGHT,SCREEN_WIDTH,SCREEN_HEIGHT/2);
		graphics.DrawLine(SCREEN_WIDTH,SCREEN_HEIGHT/2,SCREEN_WIDTH/2,0);
		graphics.DrawLine(SCREEN_WIDTH/2,0,0,SCREEN_HEIGHT/2);
		graphics.DrawLine(0,SCREEN_HEIGHT/2,SCREEN_WIDTH/2,SCREEN_HEIGHT);
	}

	drawTimer.Start();
	effectManager.Draw(graphics);
	effectTicks= drawTimer.Stop();
	enemyManger.DrawEnemies(graphics);

#ifdef DEBUG
	profiler.AddEntry("Drew Game",timer.Stop());
	profiler.AddEntry("FPS",framesPerSecond);
	profiler.AddEntry("Drew Lerp",lerpTicks);
	profiler.AddEntry("Drew Hero",heroTicks);
	profiler.AddEntry("Drew Recurse",recurseTicks);
	profiler.AddEntry("Drew Effects",effectTicks);
#endif
}

void Game::DrawInfo(Core::Graphics graphics,float framesPerSecond,float secondsPerFrame)
{
	int yDrawPosition = 0;

#ifdef DEBUG
	graphics.DrawString(0,yDrawPosition,"1 : Wrap");
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"2 : Bounce");
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"3 : Arbitrary Bounce");
	yDrawPosition += 10;
#endif
	graphics.DrawString(0,yDrawPosition,"W/Up : Increase Velocity In The Up Direction");
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"S/Down : Increase Velocity In The Down Direction");
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"A/Left : Rotate Left");
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"D/Right : Rotate Right");
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"Space : Fire Missile");
	yDrawPosition += 10;
#ifdef DEBUG
	graphics.DrawString(0,yDrawPosition,"Ship Position : ");
	util.DrawValue(graphics,100,yDrawPosition,ship->GetPosition());
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"Ship Velocity : ");
	util.DrawValue(graphics,100,yDrawPosition,ship->GetVelocity());
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"Bounds Option : ");
	graphics.DrawString(100,yDrawPosition,boundsType);
	yDrawPosition += 10;
	util.DrawValue(graphics,0,yDrawPosition,ship->GetTranslationMatrix());
	yDrawPosition += 70;
#endif
	graphics.DrawString(0,yDrawPosition,"Seconds Per Frame:");
	util.DrawValue(graphics,130,yDrawPosition,secondsPerFrame);
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"Frames Per Second:");
	util.DrawValue(graphics,130,yDrawPosition,framesPerSecond);
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"Health:");
	util.DrawValue(graphics,80,yDrawPosition,ship->GetHealth());
	yDrawPosition += 10;
	graphics.DrawString(0,yDrawPosition,"Score:");
	util.DrawValue(graphics,80,yDrawPosition,score + ship->GetHealth() * 20);
}

float Game::GetHeight()
{
	return SCREEN_HEIGHT;
}
float Game::GetWidth()
{
	return SCREEN_WIDTH;
}
	
Screen* Game::GetNextScreen()
{
	Screen* endScreen;
	if(ship->isAlive)
	{
		endScreen = new VictoryScreen();
	}
	else
	{
		endScreen = new DefeatScreen();
	}
	endScreen->SetScore(score);
	return endScreen;
}