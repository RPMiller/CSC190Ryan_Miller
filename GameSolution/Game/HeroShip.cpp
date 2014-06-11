#include "HeroShip.h"

HeroShip::HeroShip()
{

}

HeroShip::~HeroShip(void)
{
	//delete shapes;
}

void HeroShip::Destroy()
{
	GameObject::Destroy();
	turret.Destroy();
}

void HeroShip::Init(Vector3 position)
{
	HeroShip::position = position;
	turret = BasicTurret();

	health = 10;
	normalColor = color;
	damageColor = Color(255,0,0);
	damageBlinkMaxTime = .3f;
	damageBlinkTime = damageBlinkMaxTime;

	acceleration = 25.5f;
	numberOfShapes = 19;
	shapes = new Shape[numberOfShapes];

	const float mainBodyHalfWidth = 40;
	const float mainBodyHalfHeight = 40;
	const float mainBodyHalfDepth = 60;
	const float wingishThingWidth = 60;
	const float wingishThingHeight = 50;
	const float wingishThingDepth = 30;
	const float wingWidth = 180;
	const float wingHeight = 60;
	const float wingDepth = 30;


	int shapeIndex = 0;
	Vector3 bottomLeft(-mainBodyHalfWidth,mainBodyHalfHeight,0);
	Vector3 bottomRight(mainBodyHalfWidth,mainBodyHalfHeight,0);
	Vector3 top(0,-mainBodyHalfHeight/2,0);
	Vector3 mainTop(0,-mainBodyHalfHeight,mainBodyHalfDepth);
	Vector3 deep(0,0,mainBodyHalfDepth * 2);
	Vector3 wingishLeftBottom(-mainBodyHalfWidth - wingishThingWidth / 3, mainBodyHalfHeight + wingishThingHeight /2,wingishThingDepth /3);
	Vector3 wingishLeftTop(-mainBodyHalfWidth - wingishThingWidth, -mainBodyHalfHeight - wingishThingHeight,-wingishThingDepth);
	Vector3 wingishLeftDeep(-mainBodyHalfWidth - wingishThingWidth / 2,mainBodyHalfHeight,wingishThingDepth /2);
	Vector3 wingishRightBottom(mainBodyHalfWidth + wingishThingWidth / 3, mainBodyHalfHeight + wingishThingHeight /2,wingishThingDepth /3);
	Vector3 wingishRightTop(mainBodyHalfWidth + wingishThingWidth, -mainBodyHalfHeight - wingishThingHeight,-wingishThingDepth);
	Vector3 wingishRightDeep(mainBodyHalfWidth + wingishThingWidth / 2,mainBodyHalfHeight,wingishThingDepth /2);
	Vector3 wingLeftTop(-mainBodyHalfWidth - wingWidth / 3,mainBodyHalfHeight,wingDepth/3);
	Vector3 wingLeftLow(-mainBodyHalfWidth - wingWidth / 3,mainBodyHalfHeight + wingHeight /1.4f,wingDepth/3);
	Vector3 wingLeftBottom(-mainBodyHalfWidth - wingWidth,mainBodyHalfHeight + wingHeight,-wingDepth);
	Vector3 wingRightTop(mainBodyHalfWidth + wingWidth / 3,mainBodyHalfHeight,wingDepth/3);
	Vector3 wingRightLow(mainBodyHalfWidth + wingWidth / 3,mainBodyHalfHeight + wingHeight /1.4f,wingDepth/3);
	Vector3 wingRightBottom(mainBodyHalfWidth + wingWidth,mainBodyHalfHeight + wingHeight,-wingDepth);

	ShapeBuilder::BuildTriangle(bottomLeft,bottomRight,top,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(bottomLeft,top,mainTop,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(bottomRight,top,mainTop,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(bottomLeft,mainTop,deep,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(bottomRight,mainTop,deep,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(bottomLeft,wingishLeftBottom,wingishLeftTop,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(wingishLeftDeep,wingishLeftBottom,wingishLeftTop,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(wingishLeftDeep,wingishLeftBottom,wingishLeftTop,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(bottomRight,wingishRightBottom,wingishRightTop,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(wingishRightDeep,wingishRightBottom,wingishRightTop,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(wingishRightDeep,wingishRightBottom,wingishRightTop,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(bottomLeft,wingLeftTop,wingLeftBottom,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(bottomLeft,wingLeftLow,wingLeftBottom,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(wingLeftLow,wingLeftTop,wingLeftBottom,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(wingLeftLow,wingLeftTop,bottomLeft,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(bottomRight,wingRightTop,wingRightBottom,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(bottomRight,wingRightLow,wingRightBottom,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(wingRightLow,wingRightTop,wingRightBottom,shapes,shapeIndex);
	ShapeBuilder::BuildTriangle(wingRightLow,wingRightTop,bottomRight,shapes,shapeIndex);

	height = GetHeight();
	width = GetWidth();
	depth = GetDepth();
	MaxVelocity = Vector3(35,35,35);
}

void HeroShip::Draw(Core::Graphics graphics)
{
	GameObject::Draw(graphics);
	turret.SetPosition(position);
	turret.Draw(graphics);
}

void HeroShip::Update(Vector3 accelerationVector,float dt)
{
	velocity = accelerationVector * acceleration;
	Collideable::Update(accelerationVector,dt);

	if(velocity.x >= 0)
	{
		if(velocity.x > MaxVelocity.x)
		{
			velocity.x = MaxVelocity.x;
		}
	}
	else
	{
		if(velocity.x < -MaxVelocity.x)
		{
			velocity.x = -MaxVelocity.x;
		}
	}

	if(velocity.y >= 0)
	{
		if(velocity.y > MaxVelocity.y)
		{
			velocity.y = MaxVelocity.y;
		}
	}
	else
	{
		if(velocity.y < -MaxVelocity.y)
		{
			velocity.y = -MaxVelocity.y;
		}
	}

	turret.Update(dt);
}
	
void HeroShip::Update(float dt)
{
	Collideable::Update(dt);
	turret.Update(dt);
}

void HeroShip::Fire()
{
	turret.Fire();
}

ExplosionParticleEffect* HeroShip::ExplodeObject()
{
	ExplosionParticleEffect* explosion = new ExplosionParticleEffect(300,position);
	explosion->Init();
	explosion->SetColor(Color(255,255,255));
	return explosion;
}