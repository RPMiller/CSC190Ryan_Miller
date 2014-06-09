#include "Shape.h"


Shape::Shape(Vector3* lines,int numOfLines,Matrix4 translationMatrix):lines(lines),numOfLines(numOfLines),translationMatrix(translationMatrix)
{
		float top = lines->y;
		float bottom = top;
		for(int i = 1; i < numOfLines; i++)
		{
			float nextY = (lines + i)->y;
			if(nextY > bottom)
			{
				bottom = nextY;
			}
			else if(nextY < top)
			{
				top = nextY;
			}
		}
		height = bottom - top;

		float right = lines->x;
		float left = right;
		for(int i = 1; i < numOfLines; i++)
		{
			float nextX = (lines + i)->x;
			if(nextX > right)
			{
				right = nextX;
			}
			else if(nextX < left)
			{
				left = nextX;
			}
			width = right - left;
		}

		float back = lines->z;
		float front = back;
		for(int i = 1; i < numOfLines; i++)
		{
			float nextZ = (lines + i)->z;
			if(nextZ > back)
			{
				back = nextZ;
			}
			else if(nextZ < front)
			{
				front = nextZ;
			}
			depth = back - front;
		}
}


Shape::~Shape()
{
	//delete[] lines;
}

void Shape::DrawShape(Core::Graphics graphics,Vector3 center)
{
	center;
	if(numOfLines > 1)
	{
		Vector2 previousLine = mathUtil.TranslateTo2D(lines[0] * translationMatrix);
		
		for(int i = 1; i < numOfLines ; i++)
		{
			Vector2 nextLine = mathUtil.TranslateTo2D(lines[i] * translationMatrix);
			graphics.DrawLine(previousLine.x,previousLine.y,nextLine.x,nextLine.y);
			previousLine = nextLine;
		}
	}
}

void Shape::UpdateShape(Core::Graphics graphics,int x, int y,float dt)
{
	dt;
	graphics.DrawString(x,y,"add");
}

float Shape::GetHeight()
{
	return height;
}

float Shape::GetWidth()
{
	return width;
}

float Shape::GetDepth()
{
	return depth;
}

void Shape::SetTranslationMatrix(Matrix4 translationMatrix)
{
	Shape::translationMatrix = translationMatrix;
}

void Shape::SetPosition(Vector3 position)
{
	translationMatrix.Translate(position);
}

Matrix4 Shape::GetTranslationMatrix()
{
	return translationMatrix;
}