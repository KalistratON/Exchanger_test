#include "../headers/Point.h"

namespace curve {

	Point::Point(const double _x, const double _y, const double _z) :
		x(_x),
		y(_y),
		z(_z)
	{};

	std::ostream& operator << (std::ostream& os, const Point& point)
	{
		os << '(' << point.x << ';' << point.y << ';' << point.z << ')';
		return os;
	}

}