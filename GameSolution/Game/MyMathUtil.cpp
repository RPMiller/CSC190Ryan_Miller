#include "MyMathUtil.h"


MyMathUtil::MyMathUtil(void)
{
	/*x = Vector2(1,0);
	y = Vector2(0,1);
	z = Normalized(Vector2(1,1));*/
	MyMathUtil::center = Vector3(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,0);
}


MyMathUtil::~MyMathUtil(void)
{

}


Vector2 MyMathUtil::TranslateTo2D(Vector3 vector)
{
	Vector3 direction = Normalized(center - vector) * vector.z;
	return Vector2(vector.x + direction.x,vector.y + direction.y);
	/*if(vector.z == 0)
	{
		vector.z = .0001f;
	}
	return vector.x * x + vector.y *y + (1 / pow(vector.z,2)) * z;*/
}