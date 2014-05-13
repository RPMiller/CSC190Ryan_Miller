#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	const static int size = 2;
	float values[size][size];
	Matrix2(void);
	Matrix2(Vector2 first,Vector2 second)
	{
		values[0][0] = first.x;
		values[1][0] = second.x;
		values[0][1] = first.y;
		values[1][1] = second.y;
	}
	Matrix2::Matrix2(float first, float second, float third, float fourth)
	{
		values[0][0] = first;
		values[1][0] = second;
		values[0][1] = third;
		values[1][1] = fourth;
	}
	~Matrix2(void){}
	void Scale(float scale);
	void ScaleX(float scale);
	void ScaleY(float scale);
};

Vector2 inline operator*(const Matrix2& matrix, const Vector2& vector);
Vector2 inline operator*(const Vector2& vector,const Matrix2& matrix);
Matrix2 inline operator*(const Matrix2& left, const Matrix2& right);

Vector2 inline operator*(const Matrix2& matrix, const Vector2& vector)
{
	float x = matrix.values[0][0] * vector.x + matrix.values[0][1] * vector.y;
	float y = matrix.values[1][0] * vector.x + matrix.values[1][1] * vector.y;
	return Vector2(x,y);
}

Vector2 inline operator*(const Vector2& vector,const Matrix2& matrix)
{
	return matrix * vector;
}

Matrix2 inline operator*(const Matrix2& left, const Matrix2& right)
{
	int leftSize = left.size;
	int rightSize = right.size;
	Matrix2 matrix;
	for(int i = 0; i < leftSize * leftSize; i++)
	{
		int col = i % leftSize;
		int row = i / leftSize;
		float value = 0;
		for(int j = 0; j < rightSize; j++)
		{
			value += left.values[j][row] * right.values[col][j];
		}
		matrix.values[col][row] = value;
	}
	return matrix;
}

Matrix2 inline operator*(const Matrix2& input, const float scale)
{
	Matrix2 matrix;
	for(int i = 0; i < matrix.size; i ++)
	{
		for(int j = 0; j < matrix.size; j ++)
		{
			matrix.values[i][j] = scale * input.values[i][j];
		}
	}
	return matrix;
}