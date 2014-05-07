#include "Vector2.h"

std::ostream& operator<<(std::ostream& stream, const Vector2& right)
{
	std::cout << "{" << right.x << " , " << right.y << "}";
	return stream;
}