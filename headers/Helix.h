#pragma once
#include "Figure.h"

namespace curve {

	class Helix : public Figure
	{
		double R;
		double step;

	public:

		explicit Helix(const double, const double);

		Helix() = delete;

		Helix(const Helix&) = delete;
		Helix(Helix&&) = delete;

		Helix& operator = (const Helix&) = delete;
		Helix& operator = (Helix&&) = delete;

		~Helix() = default;

		Point getPoint(const double t) const override;
		Point getDerivative(const double t) const override;
		const char* getName() const override;
	};

}

