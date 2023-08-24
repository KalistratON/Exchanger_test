#include "../headers/Circle.h"
#include <cmath>
#include <stdexcept>

namespace curve {

	Circle::Circle(const double _R) : R(_R)
	{
		if (R < .0)
			throw std::invalid_argument("Negative radius : R < 0");
	}

	Point Circle::getPoint(const double t) const noexcept
	{
		return Point(R * std::cos(t), R * std::sin(t), 0);
	}

	Point Circle::getDerivative(const double t) const noexcept
	{
		return Point(-R * std::sin(t), R * std::cos(t), 0);
	}

	double Circle::getRadius() const
	{
		return R;
	}

	const char* Circle::getName() const
	{
		return "Circle";
	}

}