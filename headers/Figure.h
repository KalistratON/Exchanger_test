#pragma once

#include "Point.h"

namespace curve {

	extern const double Phi;

	class Figure
	{
	public:
		virtual Point getPoint(const double t) const = 0;
		virtual Point getDerivative(const double t) const = 0;
		virtual const char* getName() const = 0;
	};

}