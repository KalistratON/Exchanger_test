#include "../headers/Helix.h"

#include <cmath>
#include <stdexcept>

namespace curve {

	Helix::Helix(const double _R, const double _step) :
		R(_R),
		step(_step)
	{
		if (R < .0)
			throw std::invalid_argument("Negative radius : R < 0");
	}

	Point Helix::getPoint(const double t) const
	{
		return Point(R * std::cos(t), R * std::sin(t), step * t / 2 / Phi);
	}

	Point Helix::getDerivative(const double t) const
	{
		return Point(-R * std::sin(t), R * std::cos(t), step / 2 / Phi);
	}

	const char* Helix::getName() const
	{
		return "Helix";
	}
}