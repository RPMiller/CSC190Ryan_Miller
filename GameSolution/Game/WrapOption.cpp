#include "WrapOption.h"



WrapOption::WrapOption(void)
{
}


WrapOption::~WrapOption(void)
{
}


void WrapOption::CheckBounds(GameObject* gameObject,float screenHeight,float screenWidth)
{
		if(gameObject->GetPosition().x > screenWidth + gameObject->GetWidth() / 2)
		{
			gameObject->SetPosition(Vector2(0,gameObject->GetPosition().y));
		}
		else if(gameObject->GetPosition().x + gameObject->GetWidth() / 2 < 0)
		{
			gameObject->SetPosition(Vector2(screenWidth,gameObject->GetPosition().y));
		}
		else if(gameObject->GetPosition().y > screenHeight + gameObject->GetHeight() / 2)
		{
			gameObject->SetPosition(Vector2(gameObject->GetPosition().x,0));
		}
		else if(gameObject->GetPosition().y + gameObject->GetHeight() / 2 < 0)
		{
			gameObject->SetPosition(Vector2(gameObject->GetPosition().x,screenHeight));
		}
}