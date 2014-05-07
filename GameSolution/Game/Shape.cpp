#include "Shape.h"


Shape::Shape(Vector2* lines,int numOfLines,Vector2 position):lines(lines),numOfLines(numOfLines),position(position)
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
}


Shape::~Shape()
{
	//delete[] lines;
}

void Shape::DrawShape(Core::Graphics graphics)
{
	if(numOfLines > 1)
	{
		Vector2 previousLine = lines[0];
		for(int i = 1; i < numOfLines ; i++)
		{
			Vector2 nextLine = lines[i];
			graphics.DrawLine(previousLine.x + position.x,previousLine.y + position.y,nextLine.x + position.x,nextLine.y + position.y);
			previousLine = nextLine;
		}
	}
}

void Shape::UpdateShape(Core::Graphics graphics,int x, int y,float dt)
{
	dt = 2000;
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

void Shape::SetPosition(Vector2 position)
{
	Shape::position = position;
}

Vector2 Shape::GetPosition()
{
	return position;
}