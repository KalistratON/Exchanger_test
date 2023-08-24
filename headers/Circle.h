#pragma once

#include "Figure.h"

namespace curve {

	class Circle : public Figure
	{

		double R;

	public:

		explicit Circle(const double);

		Circle() = delete;

		Circle(const Circle&) = delete;
		Circle(Circle&&) = delete;

		Circle& operator = (const Circle&) = delete;
		Circle& operator = (Circle&&) = delete;

		~Circle() = default;

		Point getPoint(const double t) const noexcept override;
		Point getDerivative(const double t) const noexcept override;

		double getRadius() const;
		const char* getName() const override;
	};

}