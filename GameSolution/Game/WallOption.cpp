#include "WallOption.h"


WallOption::WallOption(void)
{
}


WallOption::~WallOption(void)
{
}

void WallOption::CheckBounds(GameObject* gameObject,float screenHeight,float screenWidth)
{
		if(gameObject->GetPosition().x > screenWidth + gameObject->GetWidth() / 2)
		{
			gameObject->SetPosition(Vector3(screenWidth,gameObject->GetPosition().y,gameObject->GetPosition().z));
		}
		else if(gameObject->GetPosition().x + gameObject->GetWidth() / 2 < 0)
		{
			gameObject->SetPosition(Vector3(0,gameObject->GetPosition().y,gameObject->GetPosition().z));
		}
		else if(gameObject->GetPosition().y > screenHeight + gameObject->GetHeight() / 2)
		{
			gameObject->SetPosition(Vector3(gameObject->GetPosition().x,screenHeight,gameObject->GetPosition().z));
		}
		else if(gameObject->GetPosition().y + gameObject->GetHeight() / 2 < 0)
		{
			gameObject->SetPosition(Vector3(gameObject->GetPosition().x,0,gameObject->GetPosition().z));
		}
}