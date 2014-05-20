#include "Lerper.h"


Lerper::Lerper(void)
{
}


Lerper::~Lerper(void)
{
}

void Lerper::Init(Vector2 position)
{
	Lerper::translationMatrix.Translate(position);

	acceleration = 2;
	const int numberOfLines = 5;
	Vector2* lines = new Vector2[numberOfLines];
	lines[0] = Vector2(0,-20);
	lines[1] = Vector2(20,0);
	lines[2] = Vector2(0,20);
	lines[3] = Vector2(-20,20);
	lines[4] = Vector2(0,-20);
	Shape shape = Shape(lines,numberOfLines,translationMatrix);
	numberOfShapes = 1;
	height = shape.GetHeight();
	width = shape.GetWidth();
	//Shape shipShapes[] = {shape};
	shapes = new Shape(lines,numberOfLines,translationMatrix);

	currentWayPointIndex = 0;
	const int numberOfWayPoints = 4;
	wayPoints = new Vector2[numberOfWayPoints];
	wayPoints[0] = Vector2(500,200);
	wayPoints[1] = Vector2(700,0);
	wayPoints[2] = Vector2(20,200);
	wayPoints[3] = Vector2(333,666);
}

void Lerper::Update(Vector2 accelerationVector)
{
	accelerationVector = Vector2();
	Vector2 currentPoint = wayPoints[currentWayPointIndex];
	Vector2 differenceVector = currentPoint - translationMatrix.GetPosition();
	velocity = Normalized(differenceVector) * 2;
	if(Length(differenceVector) < 2)
	{
		if(currentWayPointIndex > 2)
		{
			currentWayPointIndex = 0;
		}
		else
		{
			currentWayPointIndex++;
		}
	}
}