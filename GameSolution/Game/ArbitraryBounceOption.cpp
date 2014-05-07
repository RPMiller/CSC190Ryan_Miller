#include "ArbitraryBounceOption.h"


ArbitraryBounceOption::ArbitraryBounceOption(void)
{
}


ArbitraryBounceOption::~ArbitraryBounceOption(void)
{
}

void ArbitraryBounceOption::CheckBounds(GameObject* gameObject,float screenHeight,float screenWidth)
{
	bounceOption.CheckBounds(gameObject,screenHeight,screenWidth);

	Vector2 shipFromWall1 = Vector2(screenWidth/2,0) - gameObject->GetPosition();
	Vector2 wall1 = Vector2(screenWidth/2,0) - Vector2 (screenWidth,screenHeight/2);
	Vector2 shipFromWallAfterMove1 = Vector2(screenWidth/2,0) - (gameObject->GetPosition() + gameObject->GetVelocity());
	
	Vector2 shipFromWall2 = Vector2 (screenWidth,screenHeight/2) - gameObject->GetPosition();
	Vector2 wall2 = Vector2 (screenWidth,screenHeight/2) - Vector2(screenWidth/2,screenHeight);
	Vector2 shipFromWallAfterMove2 = Vector2(screenWidth,screenHeight/2) - (gameObject->GetPosition() + gameObject->GetVelocity());
	
	Vector2 shipFromWall3 = Vector2(screenWidth/2,screenHeight) - gameObject->GetPosition();
	Vector2 wall3 = Vector2(screenWidth/2,screenHeight) - Vector2(0,screenHeight/2);
	Vector2 shipFromWallAfterMove3 = Vector2(screenWidth/2,screenHeight) - (gameObject->GetPosition() + gameObject->GetVelocity());
	
	Vector2 shipFromWall4 = Vector2(0,screenHeight/2) - gameObject->GetPosition();
	Vector2 wall4 = Vector2(0,screenHeight/2) - Vector2(screenWidth/2,0);
	Vector2 shipFromWallAfterMove4 = Vector2(0,screenHeight/2) - (gameObject->GetPosition() + gameObject->GetVelocity());
	
	
	IsInBounds(shipFromWall1,shipFromWallAfterMove1,wall1,gameObject);
	IsInBounds(shipFromWall2,shipFromWallAfterMove2,wall2,gameObject);
	IsInBounds(shipFromWall3,shipFromWallAfterMove3,wall3,gameObject);
	IsInBounds(shipFromWall4,shipFromWallAfterMove4,wall4,gameObject);
}

void ArbitraryBounceOption::IsInBounds(Vector2 shipFromWall,Vector2 shipFromWallAfterMove,Vector2 wall,GameObject* gameObject)
{
	Vector2 normal = Normalized(wall) * wall * PerpCCW(wall);
	float dist = shipFromWall * normal;
	float distAfterMove = shipFromWallAfterMove * normal;
	if(dist * distAfterMove < 0)
	{
		Vector2 normalizedNormal = Normalized(normal);
		gameObject->SetVelocity(gameObject->GetVelocity() - 2 * (gameObject->GetVelocity() * normalizedNormal) * normalizedNormal);
	}
}