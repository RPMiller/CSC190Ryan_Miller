#pragma once
#include <math.h>
#include "Vector3.h"
#include "Vector4.h"

class Matrix4
{
public:
	const static int size = 4;
	float values[size][size];
	Matrix4(void)
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

	~Matrix4(void){};
	Matrix4(float first, float second, float third, float fourth, float fifth, float sixth, float seventh, float eighth, float ninth,float tenth,float eleventh,float twelvth,float thirteenth,float fourteenth,float fifteenth,float sixteenth)
	{
		values[0][0] = first;
		values[1][0] = second;
		values[2][0] = third;
		values[3][0] = fourth;
		values[0][1] = fifth;
		values[1][1] = sixth;
		values[2][1] = seventh;
		values[3][1] = eighth;
		values[0][2] = ninth;
		values[1][2] = tenth;
		values[2][2] = eleventh;
		values[3][2] = twelvth;
		values[0][3] = thirteenth;
		values[1][3] = fourteenth;
		values[2][3] = fifteenth;
		values[3][3] = sixteenth;
	}

	operator float*(){return &values[0][0];}

	void Translate(float translationX,float translationY,float translationZ);
	void Translate(Vector3 translation);
	void TranslateX(float translationX);
	void TranslateY(float translationY);
	void TranslateZ(float translationZ);
	void RotateAroundX(float rads);
	void RotateAroundY(float rads);
	void RotateAroundZ(float rads);
	Vector3 GetPosition();
};

Matrix4 inline operator*(const Matrix4& left, const Matrix4& right);
Vector4 inline operator*(const Matrix4& matrix, const Vector4& vector);

inline void Matrix4::Translate(float translationX,float translationY,float translationZ)
{
	Matrix4 trans;
	trans.values[0][3] = translationX;
	trans.values[1][3] = translationY;
	trans.values[2][3] = translationZ;
	*this = *this * trans;
}

inline void Matrix4::Translate(Vector3 translation)
{
	Matrix4 trans;
	trans.values[0][3] = translation.x;
	trans.values[1][3] = translation.y;
	trans.values[2][3] = translation.z;
	*this = *this * trans;
}

inline void Matrix4::TranslateX(float translationX)
{
	Matrix4 trans;
	trans.values[0][3] = translationX;
	*this = *this * trans;
}

inline void Matrix4::TranslateY(float translationY)
{
	Matrix4 trans;
	trans.values[1][3] = translationY;
	*this = *this * trans;
}

inline void Matrix4::TranslateZ(float translationZ)
{
	Matrix4 trans;
	trans.values[2][3] = translationZ;
	*this = *this * trans;
}

Matrix4 inline operator*(const Matrix4& left, const Matrix4& right)
{
	int leftSize = left.size;
	int rightSize = right.size;
	Matrix4 matrix;
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

inline void Matrix4::RotateAroundX(float rads)
{
	float s = sin(rads);
	float c = cos(rads);
	Matrix4 rotation;
	rotation.values[1][1] = c;
	rotation.values[2][1] = -s;
	rotation.values[1][2] = s;
	rotation.values[2][2] = c;
	*this = *this * rotation;
}

inline void Matrix4::RotateAroundY(float rads)
{
	float s = sin(rads);
	float c = cos(rads);
	Matrix4 rotation;
	rotation.values[0][0] = c;
	rotation.values[2][0] = s;
	rotation.values[0][2] = -s;
	rotation.values[2][2] = c;
	*this = *this * rotation;
}
inline void Matrix4::RotateAroundZ(float rads)
{
	float s = sin(rads);
	float c = cos(rads);
	Matrix4 rotation;
	rotation.values[0][0] = c;
	rotation.values[1][0] = -s;
	rotation.values[0][1] = s;
	rotation.values[1][1] = c;
	*this = *this * rotation;
}

inline Vector3 Matrix4::GetPosition()
{
	return Vector3(values[0][3],values[1][3],values[2][3]);
}

Vector4 inline operator*(const Matrix4& matrix, const Vector4& vector)
{
	float x = matrix.values[0][0] * vector.x + matrix.values[0][1] * vector.y + matrix.values[0][2] * vector.z + matrix.values[0][3] * vector.w;
	float y = matrix.values[1][0] * vector.x + matrix.values[1][1] * vector.y + matrix.values[1][2] * vector.z + matrix.values[1][3] * vector.w;
	float z = matrix.values[2][0] * vector.x + matrix.values[2][1] * vector.y + matrix.values[2][2] * vector.z + matrix.values[2][3] * vector.w;
	float w = matrix.values[3][0] * vector.x + matrix.values[3][1] * vector.y + matrix.values[3][2] * vector.z + matrix.values[3][3] * vector.w;
	return Vector4(x,y,z,w);
}

Vector4 inline operator*(const Vector4& vector,const Matrix4& matrix)
{
	return matrix * vector;
}

Vector3 inline operator*(const Vector3& vector,const Matrix4& matrix)
{
	Vector4 result = matrix * Vector4(vector.x,vector.y,vector.z,1);
	return Vector3(result.x,result.y,result.z);
}