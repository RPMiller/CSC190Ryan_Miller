#include "Vector3.h"


std::ostream& operator<<(std::ostream& stream, const Vector3& right)
{
	std::cout << "{" << right.x << " , " << right.y <<  " , " << right.z << "}";
	return stream;
}