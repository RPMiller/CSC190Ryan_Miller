#include "Utilities.h"
#include "Matrix3.h"
#include <iomanip>


Utilities::Utilities(void)
{
}


Utilities::~Utilities(void)
{
}

void Utilities::DrawValue( Core::Graphics& graphics, int x, int y, float num ) {
	stringstream ss;
	ss << num;
	graphics.DrawString( x, y, ss.str().c_str());
}

void Utilities::DrawValue( Core::Graphics& graphics, int x, int y, int num )
{
	stringstream ss;
	ss << num;
	graphics.DrawString( x, y, ss.str().c_str());
}


void Utilities::DrawValue( Core::Graphics& graphics, int x, int y, size_t val )
{
	stringstream ss;
	ss << val;
	graphics.DrawString( x, y, ss.str().c_str());
}

void Utilities::DrawValue( Core::Graphics& graphics, int x, int y, Vector2 vector )
{
	stringstream ss;
	ss << "X: " << vector.x << " , y: " << vector.y;
	graphics.DrawString( x, y, ss.str().c_str());
}

void Utilities::DrawValue( Core::Graphics& graphics, int x, int y, Matrix3 matrix )
{
	int xOff = 70;
	int yOff = 20;

	for(int i = 0; i < matrix.size; i++)
	{
		for(int j = 0; j < matrix.size; j++)
		{
			stringstream ss;
			ss << std::setprecision(6) << matrix.values[j][i];
			graphics.DrawString( x + xOff * i, y + yOff * j, ss.str().c_str());
		}
	}
}


void Utilities::DrawValue( Core::Graphics& graphics, int x, int y, Vector3 vector )
{
	stringstream ss;
	ss << "X: " << vector.x << " , y: " << vector.y << " , z " << vector.z;
	graphics.DrawString( x, y, ss.str().c_str());
}

void Utilities::DrawValue( Core::Graphics& graphics, int x, int y, Matrix4 matrix )
{
	int xOff = 70;
	int yOff = 20;

	for(int i = 0; i < matrix.size; i++)
	{
		for(int j = 0; j < matrix.size; j++)
		{
			stringstream ss;
			ss << std::setprecision(6) << matrix.values[j][i];
			graphics.DrawString( x + xOff * i, y + yOff * j, ss.str().c_str());
		}
	}
}