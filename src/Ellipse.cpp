#include "../headers/Ellipse.h"

#include <cmath>
#include <stdexcept>

namespace curve {

	Ellipse::Ellipse(const double _a, const double _b) :
		a(_a),
		b(_b)
	{
		if (a < .0 || b < 0)
			throw std::invalid_argument("Negative axis : a < 0 OR b < 0");
	}

	Point Ellipse::getPoint(const double t) const
	{
		return Point(a * std::cos(t), b * std::sin(t), 0);
	}

	Point Ellipse::getDerivative(const double t) const
	{
		return Point(-a * std::sin(t), b * std::cos(t), 0);
	}

	const char* Ellipse::getName() const
	{
		return "Ellipse";
	}

}