#pragma once
#include "Figure.h"

namespace curve {

	class Ellipse : public Figure
	{
		double a;
		double b;

	public:

		explicit Ellipse(const double, const double);

		Ellipse() = delete;

		Ellipse(const Ellipse&) = delete;
		Ellipse(Ellipse&&) = delete;

		Ellipse& operator = (const Ellipse&) = delete;
		Ellipse& operator = (Ellipse&&) = delete;

		~Ellipse() = default;

		virtual Point getPoint(const double t) const override;
		Point getDerivative(const double t) const override;
		const char* getName() const override;
	};

}
