#include "Matrix2.h"


Matrix2::Matrix2(void)
{
	for(int i = 0; i < size ; i++)
	{
		values[i][i] = 1;
	}
}

//Matrix2::Matrix2(float first, float second, float third, float fourth)
//{
//	values[0][0] = first;
//	values[1][0] = second;
//	values[0][1] = third;
//	values[1][1] = fourth;
//}

//Matrix2::~Matrix2(void)
//{
//}

void Matrix2::Scale(float scale)
{
	Matrix2 identity;
	for(int i = 0; i < size; i++)
	{
		identity.values[i][i] *= scale;
	}
	*this * identity;
}
void Matrix2::ScaleX(float scale)
{
	Matrix2 identity;
	identity.values[0][0] = scale;
	*this * identity;
}
void Matrix2::ScaleY(float scale)
{
	Matrix2 identity;
	identity.values[1][1] = scale;
	*this * identity;
}