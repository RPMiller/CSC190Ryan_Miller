#ifndef VECTOR2H
#define VECTOR2H
#include<math.h>
#include<iostream>
struct Vector2
{
	float x, y;
	Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2(float x,float y):x(x), y(y)
	{

	}
	operator float*(){return &x;}
};

Vector2 inline Normalized(const Vector2& vector);
Vector2 inline PerpCCW(Vector2 vector);
Vector2 inline PerpCW(Vector2 vector);
Vector2 inline LERP(Vector2 first, Vector2 second, float beta);
Vector2 inline projLR(Vector2 left,Vector2 right);
float inline Dot(const Vector2& left, const Vector2& right);
Vector2 inline rejLR(Vector2 left,Vector2 right);
float inline Length(const Vector2& vector);
float inline LengthSquared(const Vector2& vector);
float inline Cross(const Vector2& left, const Vector2& right);


 Vector2 inline operator+(const Vector2& left, const Vector2& right)
{
	return Vector2(left.x + right.x, left.y + right.y);
}

Vector2 inline operator-(const Vector2& left, const Vector2& right)
{
	return Vector2(left.x - right.x, left.y - right.y);
}

Vector2 inline operator-(const Vector2& vector)
{
	return Vector2(-vector.x, -vector.y);
}

Vector2 inline operator*(const float scale, const Vector2& right)
{
	return Vector2(scale * right.x, scale * right.y);
}

Vector2 inline operator*(const Vector2& left,const float scale)
{
	return Vector2(scale * left.x, scale * left.y);
}

float inline operator*(const Vector2& left, const Vector2& right)
{
	return left.x * right.x + (left.y * right.y);
}

Vector2 inline operator/(const Vector2& left,float scale)
{
	if(scale == 0)
	{
		scale = .0000000000001f;
	}
	return Vector2(left.x / scale, left.y/scale);
}

std::ostream& operator<<(std::ostream& stream, const Vector2& right)
{
	std::cout << "{" << right.x << " , " << right.y << "}";
	return stream;
}

Vector2 inline Normalized(const Vector2& vector)
{
	return Vector2(vector / Length(vector));
}

Vector2 inline PerpCCW(Vector2 vector)
{
	return Vector2(-vector.y,vector.x);
}

Vector2 inline PerpCW(Vector2 vector)
{
	return Vector2(vector.y,-vector.x);
}

Vector2 inline LERP(Vector2 first, Vector2 second, float beta)
{
	return (1 - beta) * first + beta * second;
}

Vector2 inline projLR(Vector2 left,Vector2 right)
{
	return (left * right) / Length(left) * Normalized(left);
}

float Dot(const Vector2& left, const Vector2& right)
{
	return left * right;
}

Vector2 inline rejLR(Vector2 left,Vector2 right)
{
	return right - projLR(left,right);
}

float inline Length(const Vector2& vector)
{
	return sqrt(LengthSquared(vector));
}

float LengthSquared(const Vector2& vector)
{
	return pow(vector.x,2.0f) + pow(vector.y,2.0f);
}

float Cross(const Vector2& left, const Vector2& right)
{
	return (left.x * right.y) - (left.y * right.x);
}
#endif
