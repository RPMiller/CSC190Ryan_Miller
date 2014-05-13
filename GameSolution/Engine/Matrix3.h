#pragma once
#include "Vector3.h"
#include "Vector2.h"
class Matrix3
{
public:
	const static int size = 3;
	float values[size][size];
	Matrix3::Matrix3(void)
{
	for(int i = 0; i < size; i++)
	{
		for( int j = 0 ; j < size; j++)
		{
			if(i == j)
			{
				values[i][j] = 1;
			}
			else	
			{
				values[i][j] = 0;
			}
		}
	}
}
	~Matrix3(void){};
	Matrix3(float first, float second, float third, float fourth, float fifth, float sixth, float seventh, float eighth, float ninth)
	{
		values[0][0] = first;
		values[1][0] = second;
		values[2][0] = third;
		values[0][1] = fourth;
		values[1][1] = fifth;
		values[2][1] = sixth;
		values[0][2] = seventh;
		values[1][2] = eighth;
		values[2][2] = ninth;
	}
	inline void Scale(float scale);
	inline void ScaleX(float scale);
	inline void ScaleY(float scale);
	inline void Rotate(float rads);
	inline void Translate(float translationX,float translationY);
	inline void Translate(Vector2 translation);
	inline void TranslateX(float translation);
	inline void TranslateY(float translation);
	operator float*(){return &values[0][0];}
};

Matrix3 inline operator*(const Matrix3& matrix, const Matrix3& vector);
Vector3 inline operator*(const Vector3& vector,const Matrix3& matrix);
Vector2 inline operator*(const Vector2& vector,const Matrix3& matrix);
Matrix3 inline operator*(const Matrix3& left, const Matrix3& right);

inline void Matrix3::Translate(float translationX,float translationY)
{
	Matrix3 trans;
	trans.values[0][2] = translationX;
	trans.values[1][2] = translationY;
	*this = *this * trans;
}

inline void Matrix3::Translate(Vector2 translation)
{
	Matrix3 trans;
	trans.values[0][2] = translation.x;
	trans.values[1][2] = translation.y;
	*this = *this * trans;
}

inline void Matrix3::TranslateX(float translation)
{
	Matrix3 trans;
	trans.values[0][2] = translation;
	*this = *this * trans;
}
	
inline void Matrix3::TranslateY(float translation)
{
	Matrix3 trans;
	trans.values[1][2] = translation;
	*this = *this * trans;
}

inline void Matrix3::Scale(float scale)
{
	Matrix3 identity;
	for(int i = 0; i < size; i++)
	{
		identity.values[i][i] *= scale;
	}
	*this = *this * identity;
}
inline void Matrix3::ScaleX(float scale)
{
	Matrix3 identity;
	identity.values[0][0] = scale;
	*this = *this * identity;
}
inline void Matrix3::ScaleY(float scale)
{
	Matrix3 identity;
	identity.values[1][1] = scale;
	*this = *this * identity;
}

inline void Matrix3::Rotate(float rads)
{
	Matrix3 rotation;
	float c = cos(rads);
	float s = sin(rads);
	rotation.values[0][0] = c;
	rotation.values[1][0] = -s;
	rotation.values[0][1] = s;
	rotation.values[1][1] = c;
	*this = *this * rotation;
}

Vector3 inline operator*(const Matrix3& matrix, const Vector3& vector)
{
	float x = matrix.values[0][0] * vector.x + matrix.values[0][1] * vector.y + matrix.values[0][2] * vector.z;
	float y = matrix.values[1][0] * vector.x + matrix.values[1][1] * vector.y + matrix.values[1][2] * vector.z;
	float z = matrix.values[2][0] * vector.x + matrix.values[2][1] * vector.y + matrix.values[2][2] * vector.z;
	return Vector3(x,y,z);
}

Vector3 inline operator*(const Vector3& vector,const Matrix3& matrix)
{
	return matrix * vector;
}

Matrix3 inline operator*(const Matrix3& left, const Matrix3& right)
{
	int leftSize = left.size;
	int rightSize = right.size;
	Matrix3 matrix;
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

Matrix3 inline operator*(const Matrix3& input, const float scale)
{
	Matrix3 matrix;
	for(int i = 0; i < matrix.size; i ++)
	{
		for(int j = 0; j < matrix.size; j ++)
		{
			matrix.values[i][j] = scale * input.values[i][j];
		}
	}
	return matrix;
}

Vector2 inline operator*(const Vector2& vector,const Matrix3& matrix)
{
	Vector3 result = matrix * Vector3(vector.x,vector.y,1);
	return Vector2(result.x,result.y);
}
