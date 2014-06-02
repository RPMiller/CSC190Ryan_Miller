#include "Game.h"

Game::Game(float ScreenWidth,float ScreenHeight) : SCREEN_HEIGHT(ScreenHeight), SCREEN_WIDTH(ScreenWidth)
{
	arbOn = false;
	boundsType = "wrap";
	boundsOption = &wrap;
	HeroShip* heroShip = new HeroShip();
	heroShip->Init(Vector2(SCREEN_WIDTH/2,SCREEN_HEIGHT/2));
	ship = heroShip;
	Lerper* lerper = new Lerper();
	lerper->Init(Vector2(SCREEN_WIDTH/2,SCREEN_HEIGHT/2));
	lerp = lerper;
	recurse = new RecursiveRotation(4,30,Vector2(120,350));
	ExplosionParticleEffect* explosion = new ExplosionParticleEffect(100,Vector2(500,500));
	explosion->Init();
	effectManager.AddEffect(ship->GetFountainParticleEffect());
	effectManager.AddEffect(explosion);
}


Game::~Game(void)
{
}

void Game::Update(float dt)
{
#ifdef DEBUG
	profiler.NewFrame();
#endif
	timer.Start();
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
	lerp->Update(Vector2(),dt);
	boundsOption->CheckBounds(ship,SCREEN_HEIGHT,SCREEN_WIDTH);
	ship->Rotate(rotate);
	ship->Update(Vector2(0,y), dt);
	effectManager.Update(dt);
	enemyManger.UpdateEnemies(ship,&effectManager,dt);
#ifdef DEBUG
	profiler.AddEntry("Updated Full Game",timer.Stop());
#endif
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
	lerp->Draw(graphics);
	lerpTicks = drawTimer.Stop();

	drawTimer.Start();
	ship->Draw(graphics);
	heroTicks= drawTimer.Stop();

	drawTimer.Start();
	recurse->Rotate(.05f,graphics);
	recurseTicks= drawTimer.Stop();

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
	graphics.DrawString(0,170,"Seconds Per Frame:");
	util.DrawValue(graphics,130,170,secondsPerFrame);
	graphics.DrawString(0,180,"Frames Per Second:");
	util.DrawValue(graphics,130,180,framesPerSecond);

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

float Game::GetHeight()
{
	return SCREEN_HEIGHT;
}
float Game::GetWidth()
{
	return SCREEN_WIDTH;
}