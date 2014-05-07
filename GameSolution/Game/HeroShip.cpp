#include "HeroShip.h"


HeroShip::HeroShip(void)
{
}


HeroShip::~HeroShip(void)
{
	delete shapes;
}

void HeroShip::Init(Vector2 position)
{
	HeroShip::position = position;

	acceleration = 2;
	const int numberOfLines = 7;
	Vector2* lines = new Vector2[numberOfLines];
	lines[0] = Vector2(0,-20);
	lines[1] = Vector2(20,0);
	lines[2] = Vector2(20,20);
	lines[3] = Vector2(0,0);
	lines[4] = Vector2(-20,20);
	lines[5] = Vector2(-20,0);
	lines[6] = Vector2(0,-20);
	Shape shape = Shape(lines,numberOfLines,position);
	numberOfShapes = 1;
	height = shape.GetHeight();
	width = shape.GetWidth();
	//Shape shipShapes[] = {shape};
	shapes = new Shape(lines,numberOfLines,position);
}