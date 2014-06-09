#include "BounceOption.h"


BounceOption::BounceOption(void)
{
}


BounceOption::~BounceOption(void)
{
}


void BounceOption::CheckBounds(GameObject* gameObject,float screenHeight,float screenWidth)
{
		if(gameObject->GetPosition().x > screenWidth - gameObject->GetWidth() / 2
			|| gameObject->GetPosition().x - gameObject->GetWidth() / 2 < 0)
		{
			gameObject->SetVelocity(Vector3(-gameObject->GetVelocity().x,gameObject->GetVelocity().y,gameObject->GetVelocity().z));
		}
		else if(gameObject->GetPosition().y > screenHeight - gameObject->GetHeight() / 2
			|| gameObject->GetPosition().y - gameObject->GetHeight() / 2 < 0)
		{
			gameObject->SetVelocity(Vector3(gameObject->GetVelocity().x,-gameObject->GetVelocity().y,gameObject->GetVelocity().z));
		}
}