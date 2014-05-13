#pragma once
#include<iostream>
class Vector3
{
	public:
	float x, y, z;
	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3(float x,float y,float z):x(x), y(y),z(z)
	{

	}
	operator float*(){return &x;}
};

Vector3 inline Normalized(const Vector3& vector);
Vector3 inline PerpCCW(Vector3 vector);
Vector3 inline PerpCW(Vector3 vector);
Vector3 inline LERP(Vector3 first, Vector3 second, float beta);
Vector3 inline projLR(Vector3 left,Vector3 right);
float inline Dot(const Vector3& left, const Vector3& right);
Vector3 rejLR(Vector3 left,Vector3 right);
float inline Length(const Vector3& vector);
float inline LengthSquared(const Vector3& vector);
float inline Cross(const Vector3& left, const Vector3& right);
Vector3 inline operator+(const Vector3& left, const Vector3& right)
{
	return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3 inline operator-(const Vector3& left, const Vector3& right)
{
	return Vector3(left.x - right.x, left.y - right.y,left.z - right.z);
}

Vector3 inline operator-(const Vector3& vector)
{
	return Vector3(-vector.x, -vector.y,-vector.z);
}

Vector3 inline operator*(const float scale, const Vector3& right)
{
	return Vector3(scale * right.x, scale * right.y,scale * right.z);
}

Vector3 inline operator*(const Vector3& left,const float scale)
{
	return Vector3(scale * left.x, scale * left.y, scale * left.z);
}

float inline operator*(const Vector3& left, const Vector3& right)
{
	return left.x * right.x + (left.y * right.y) + (left.z * right.z);
}

Vector3 inline operator/(const Vector3& left,float scale)
{
	if(scale == 0)
	{
		scale = .0000000000001f;
	}
	return Vector3(left.x / scale, left.y/scale, left.z / scale);
}
