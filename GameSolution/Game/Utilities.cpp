#include "Utilities.h"


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

void Utilities::DrawValue( Core::Graphics& graphics, int x, int y, Vector2 vector )
{
	stringstream ss;
	ss << "X: " << vector.x << " , y: " << vector.y;
	graphics.DrawString( x, y, ss.str().c_str());
}