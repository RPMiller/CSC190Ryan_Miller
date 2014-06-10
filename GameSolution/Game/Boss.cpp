#include "Boss.h"


Boss::Boss(void)
{

}


Boss::~Boss(void)
{
}

bool Boss::CheckCollision(Missile* missile)
{
	if(leftEye.isAlive)
	{
		if(leftEye.CheckCollision(missile))
		{
 			missile->isAlive = false;
		}
	}
	if(rightEye.CheckCollision(missile))
	{
   		missile->isAlive = false;
	}
	if(!rightEye.isAlive)
	{
		rightEye.SetColor(Color(255,255,255));
	}
	if(!leftEye.isAlive)
	{
		leftEye.SetColor(Color(255,255,255));
	}
	isAlive = leftEye.isAlive || rightEye.isAlive;
	return isAlive;
}
	
ExplosionParticleEffect* Boss::ExplodeObject()
{
	return new ExplosionParticleEffect(500,position);
}
	
void Boss::Init(Vector3 position)
{
	Boss::position = position;
	leftEye.Init(position);
	rightEye.Init(position);
	health = 1000000;

	color = Color(255,255,255);

	numberOfShapes = 15;
	shapes = new Shape[numberOfShapes];

	const float BOSS_HALF_WIDTH = 400;
	const float BOSS_HALF_HEIGHT = 370;
	const float BOSS_HALF_DEPTH = 150;
	const float HEIGHT_OFF_SET = 100;
	const float BASE_OFFSET = 50;

	int startIndex = 0;

	//corners
	Vector3 topLeft(-BOSS_HALF_WIDTH + BASE_OFFSET,-BOSS_HALF_HEIGHT + HEIGHT_OFF_SET,BOSS_HALF_DEPTH);
	Vector3 topRight(BOSS_HALF_WIDTH - BASE_OFFSET,-BOSS_HALF_HEIGHT + HEIGHT_OFF_SET,BOSS_HALF_DEPTH);
	Vector3 bottomLeft(-BOSS_HALF_WIDTH + BASE_OFFSET* 6,BOSS_HALF_HEIGHT + HEIGHT_OFF_SET,BOSS_HALF_DEPTH);
	Vector3 bottomRight(BOSS_HALF_WIDTH - BASE_OFFSET* 6,BOSS_HALF_HEIGHT + HEIGHT_OFF_SET,BOSS_HALF_DEPTH);

	//left
	Vector3 LEFTVfarLeft(-BOSS_HALF_WIDTH,-BOSS_HALF_HEIGHT + BASE_OFFSET + HEIGHT_OFF_SET,BOSS_HALF_DEPTH -BASE_OFFSET);
	Vector3 LEFTVfarLeftLast(-BOSS_HALF_WIDTH + BASE_OFFSET,-BOSS_HALF_HEIGHT + BASE_OFFSET + HEIGHT_OFF_SET,BOSS_HALF_DEPTH -BASE_OFFSET);
	Vector3 LEFTVleftQuadBotLeft(-BOSS_HALF_WIDTH,0 + HEIGHT_OFF_SET,BOSS_HALF_DEPTH);
	Vector3 LEFTVleftQuadBotRight(-BOSS_HALF_WIDTH + BASE_OFFSET,0 + HEIGHT_OFF_SET,0);
	Vector3 LEFTVleftFaceIndent(-BASE_OFFSET * 6,HEIGHT_OFF_SET + BASE_OFFSET * 2,BOSS_HALF_DEPTH);
	Vector3 LEFTVbottomLeftQuad(-BOSS_HALF_WIDTH + BASE_OFFSET * 2,BOSS_HALF_WIDTH / 2 + HEIGHT_OFF_SET,-BASE_OFFSET /2);
	Vector3 LEFTVbottomRightQuad(-BOSS_HALF_WIDTH + BASE_OFFSET * 3,BOSS_HALF_WIDTH / 2 + HEIGHT_OFF_SET - BASE_OFFSET,0);

	//right
	Vector3 RIGHTVfarLeft(-LEFTVfarLeft.x,LEFTVfarLeft.y,LEFTVfarLeft.z);
	Vector3 RIGHTVfarLeftLast(-LEFTVfarLeftLast.x,LEFTVfarLeftLast.y,LEFTVfarLeftLast.z);
	Vector3 RIGHTVleftQuadBotLeft(-LEFTVleftQuadBotLeft.x,LEFTVleftQuadBotLeft.y,LEFTVleftQuadBotLeft.z);
	Vector3 RIGHTVleftQuadBotRight(-LEFTVleftQuadBotRight.x,LEFTVleftQuadBotRight.y,LEFTVleftQuadBotRight.z);
	Vector3 RIGHTVleftFaceIndent(-LEFTVleftFaceIndent.x,LEFTVleftFaceIndent.y,LEFTVleftFaceIndent.z);
	Vector3 RIGHTVbottomLeftQuad(-LEFTVbottomLeftQuad.x,LEFTVbottomLeftQuad.y,LEFTVbottomLeftQuad.z);
	Vector3 RIGHTVbottomRightQuad(-LEFTVbottomRightQuad.x,LEFTVbottomRightQuad.y,LEFTVbottomRightQuad.z);

	//center
	Vector3 bottomCenter(0,BOSS_HALF_HEIGHT / 1.5f, -BOSS_HALF_DEPTH);
	Vector3 topCenter(0,-BOSS_HALF_HEIGHT,0);

	//left
	ShapeBuilder::BuildTriangle(topLeft,LEFTVfarLeft,LEFTVfarLeftLast,shapes,startIndex);
	ShapeBuilder::BuildQuad(LEFTVfarLeftLast,LEFTVfarLeft,LEFTVleftQuadBotRight,LEFTVleftQuadBotLeft,shapes,startIndex);
	ShapeBuilder::BuildTriangle(LEFTVleftQuadBotLeft,LEFTVleftQuadBotRight,LEFTVleftFaceIndent,shapes,startIndex);
	ShapeBuilder::BuildQuad(LEFTVbottomLeftQuad,LEFTVbottomRightQuad,LEFTVleftQuadBotRight,LEFTVbottomLeftQuad,shapes,startIndex);
	ShapeBuilder::BuildTriangle(bottomLeft,LEFTVbottomRightQuad,LEFTVbottomLeftQuad,shapes,startIndex);
	//right
	ShapeBuilder::BuildTriangle(topRight,RIGHTVfarLeft,RIGHTVfarLeftLast,shapes,startIndex);
	ShapeBuilder::BuildQuad(RIGHTVfarLeftLast,RIGHTVfarLeft,RIGHTVleftQuadBotRight,RIGHTVleftQuadBotLeft,shapes,startIndex);
	ShapeBuilder::BuildTriangle(RIGHTVleftQuadBotLeft,RIGHTVleftQuadBotRight,RIGHTVleftFaceIndent,shapes,startIndex);
	ShapeBuilder::BuildQuad(RIGHTVbottomLeftQuad,RIGHTVbottomRightQuad,RIGHTVleftQuadBotRight,RIGHTVbottomLeftQuad,shapes,startIndex);
	ShapeBuilder::BuildTriangle(bottomRight,RIGHTVbottomRightQuad,RIGHTVbottomLeftQuad,shapes,startIndex);

	//center
	ShapeBuilder::BuildTriangle(bottomRight,bottomLeft,bottomCenter,shapes,startIndex);
	ShapeBuilder::BuildTriangle(bottomCenter,RIGHTVleftQuadBotRight,bottomRight,shapes,startIndex);
	ShapeBuilder::BuildTriangle(bottomCenter,LEFTVleftQuadBotRight,bottomLeft,shapes,startIndex);
	ShapeBuilder::BuildTriangle(topCenter,topLeft,LEFTVfarLeft,shapes,startIndex);
	ShapeBuilder::BuildTriangle(topCenter,topRight,RIGHTVfarLeft,shapes,startIndex);
}

void Boss::FollowHero(Vector3 heroPosition,float dt)
{
	leftEye.Update(dt);
	rightEye.Update(dt);
	leftEye.Fire(heroPosition);
	rightEye.Fire(heroPosition);
	isAlive = leftEye.isAlive && rightEye.isAlive;
	if(!isAlive)
	{
		LOG(Info,"Boss Killed");
	}
	GameObject::Update(dt);
}

void Boss::Draw(Core::Graphics graphics)
{
	const int EYE_DISTANCE_WIDTH = 200;
	leftEye.SetPosition(Vector3(position.x - EYE_DISTANCE_WIDTH,position.y,position.z));
	leftEye.Draw(graphics);
	rightEye.SetPosition(Vector3(position.x + EYE_DISTANCE_WIDTH,position.y,position.z));
	rightEye.Draw(graphics);
	GameObject::Draw(graphics);
}

Missile** Boss::GetMissiles()
{
	int numberOfMissiles = leftEye.GetTurret().GetNumberOfMissiles() + rightEye.GetTurret().GetNumberOfMissiles();
	Missile** missiles = new Missile*[numberOfMissiles];
	Missile** leftMissiles = leftEye.GetTurret().GetMissiles();
	Missile** rightMissiles = rightEye.GetTurret().GetMissiles();
	for(int i = 0; i < leftEye.GetTurret().GetNumberOfMissiles(); i++)
	{
		missiles[i] = leftMissiles[i];
	}

	for(int i = leftEye.GetTurret().GetNumberOfMissiles(); i < leftEye.GetTurret().GetNumberOfMissiles() + rightEye.GetTurret().GetNumberOfMissiles();i++)
	{
		missiles[i] = rightMissiles[i - leftEye.GetTurret().GetNumberOfMissiles()];
	}
	return missiles;
}

int Boss::GetTotalMissileNumber()
{
	return leftEye.GetTurret().GetNumberOfMissiles() + rightEye.GetTurret().GetNumberOfMissiles();
}