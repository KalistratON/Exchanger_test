#pragma once

#include <ostream>

namespace curve {

	class Point
	{
		double x;
		double y;
		double z;

	public:
		Point(const double, const double, const double);

		Point() = delete;
		Point(const Point&) = default;
		Point(Point&&) = default;

		Point& operator = (const Point&) = delete;
		Point& operator = (Point&&) = delete;

		friend std::ostream& operator << (std::ostream&, const Point&);
	};

}
