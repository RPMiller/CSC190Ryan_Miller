#include "RecursiveRotation.h"


RecursiveRotation::RecursiveRotation(int numRecurse,int recurseDistance,Vector2 center) : NUM_RECURSE(numRecurse), RECURSE_DISTANCE(recurseDistance)
{
	shapes = new Shape[NUM_RECURSE];
	float shapeSize = 3;
	int numVertecies = 5;

	for(int i = 0; i < NUM_RECURSE; i++)
	{
		shapeSize += i * 2;
		Vector2* lines = new Vector2[numVertecies];
		Vector2 vertex1(shapeSize,shapeSize);
		Vector2 vertex2(shapeSize,-shapeSize);
		Vector2 vertex3(-shapeSize,-shapeSize);
		Vector2 vertex4(-shapeSize,shapeSize);

		lines[0] = vertex1;
		lines[1] = vertex2;
		lines[2] = vertex3;
		lines[3] = vertex4;
		lines[4] = vertex1;

		shapes[i] = Shape(lines,numVertecies,Matrix3());
	}
	Matrix3 translation;
	translation.Translate(center);
	shapes[0].SetTranslationMatrix(translation);
}

RecursiveRotation::~RecursiveRotation(void)
{
}

void RecursiveRotation::Rotate(float radsToRotate,Core::Graphics graphics)
{
	radsRotated += radsToRotate;
	if(NUM_RECURSE > 1)
	{
		RotateShapes(shapes[0],shapes[1],1,graphics);
	}
	shapes[0].DrawShape(graphics);
}

void RecursiveRotation::RotateShapes(Shape parent, Shape child,int childIndex,Core::Graphics graphics)
{
	Vector2 baseTranslateVector(0.0f,(float)RECURSE_DISTANCE);
	Matrix3 rotation;
	rotation.Rotate(radsRotated * childIndex);
	Matrix3 translation;
	translation.Translate((baseTranslateVector * rotation));
	translation =  parent.GetTranslationMatrix() * translation;
	child.SetTranslationMatrix(translation);
	child.DrawShape(graphics);

	int nextChild = childIndex + 1;
	if(nextChild < NUM_RECURSE)
	{
		RotateShapes(child,shapes[nextChild],nextChild,graphics);
	}
}