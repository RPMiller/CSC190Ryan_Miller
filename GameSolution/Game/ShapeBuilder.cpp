#include "ShapeBuilder.h"


ShapeBuilder::ShapeBuilder(void)
{
}


ShapeBuilder::~ShapeBuilder(void)
{
}

void ShapeBuilder::BuildCube(float size,Shape* shapes,int startIndex)
{
	const int numberOfSquareLines = 5;

	Vector3* front = new Vector3[numberOfSquareLines];
	front[0] = Vector3(-size,-size,-size);
	front[1] = Vector3(size,-size,-size);
	front[2] = Vector3(size,size,-size);
	front[3] = Vector3(-size,size,-size);
	front[4] = Vector3(-size,-size,-size);
	Shape frontCube = Shape(front,numberOfSquareLines,Matrix4());


	Vector3* back = new Vector3[numberOfSquareLines];
	back[0] = Vector3(-size,-size,size);
	back[1] = Vector3(size,-size,size);
	back[2] = Vector3(size,size,size);
	back[3] = Vector3(-size,size,size);
	back[4] = Vector3(-size,-size,size);
	Shape backCube = Shape(back,numberOfSquareLines,Matrix4());


	Vector3* top = new Vector3[numberOfSquareLines];
	top[0] = Vector3(-size,-size,-size);
	top[1] = Vector3(size,-size,-size);
	top[2] = Vector3(size,-size,size);
	top[3] = Vector3(-size,-size,size);
	top[4] = Vector3(-size,-size,-size);
	Shape topCube = Shape(top,numberOfSquareLines,Matrix4());


	Vector3* bottom = new Vector3[numberOfSquareLines];
	bottom[0] = Vector3(-size,size,-size);
	bottom[1] = Vector3(size,size,-size);
	bottom[2] = Vector3(size,size,size);
	bottom[3] = Vector3(-size,size,size);
	bottom[4] = Vector3(-size,size,-size);
	Shape bottomCube = Shape(bottom,numberOfSquareLines,Matrix4());


	Vector3* left = new Vector3[numberOfSquareLines];
	left[0] = Vector3(-size,-size,-size);
	left[1] = Vector3(-size,size,-size);
	left[2] = Vector3(-size,size,size);
	left[3] = Vector3(-size,-size,size);
	left[4] = Vector3(-size,-size,-size);
	Shape leftCube = Shape(left,numberOfSquareLines,Matrix4());


	Vector3* right = new Vector3[numberOfSquareLines];
	right[0] = Vector3(size,-size,-size);
	right[1] = Vector3(size,size,-size);
	right[2] = Vector3(size,size,size);
	right[3] = Vector3(size,-size,size);
	right[4] = Vector3(size,-size,-size);
	Shape rightCube = Shape(right,numberOfSquareLines,Matrix4());

	shapes[0 + startIndex] = frontCube;
	shapes[1 + startIndex] = backCube;
	shapes[2 + startIndex] = topCube;
	shapes[3 + startIndex] = bottomCube;
	shapes[4 + startIndex] = leftCube;
	shapes[5 + startIndex] = rightCube;
}


void ShapeBuilder::BuildTriangle(Vector3 point1,Vector3 point2,Vector3 point3,Shape* shapes,int &startIndex)
{
	const int triangleVetexes = 4;
	Vector3* triangle = new Vector3[triangleVetexes];
	triangle[0] = point1;
	triangle[1] = point2;
	triangle[2] = point3;
	triangle[3] = point1;
	shapes[startIndex] = Shape(triangle,triangleVetexes,Matrix4());
	startIndex++;
}