#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <algorithm>

#include "../headers/Circle.h"
#include "../headers/Ellipse.h"
#include "../headers/Helix.h"

using Shape = std::shared_ptr<curve::Figure>;

int main(int argc, char* argv[])
{
	try {

		std::srand(static_cast<unsigned int>(std::time(nullptr)));

		const size_t N = 10;
		std::vector<Shape> figures;
		
		auto generateType = []() -> Shape
		{
			auto random = [](bool flag)
			{
				if (flag)
					return std::rand() % 1000 / 100.0;
				else
					return std::rand() % 1000 / 10.0 - 50.0;
			};

			switch (std::rand() % 3)
			{
			case 0:
				return std::make_shared<curve::Circle>(random(true));
				break;
			case 1:
				return std::make_shared<curve::Ellipse>(random(true), random(true));
				break;
			default:
				return std::make_shared<curve::Helix>(random(true), random(false));
			}
		};

		auto iter = std::back_inserter(figures);
		std::generate_n(iter, N, generateType);

		std::cout << "Value at t = Pi / 4" << std::endl;
		const double t = curve::Phi / 4;
		std::for_each(figures.begin(), figures.end(), [&t](const Shape& shape)
			{
				std::cout << shape->getName() << " : Value : " <<
					shape->getPoint(t) << ": Derivative : " << 
					shape->getDerivative(t) << std::endl;
			});
				
		std::vector<std::shared_ptr<curve::Circle>> circles;
		std::shared_ptr<curve::Circle> temp;

		for (const auto& it : figures) if (temp = std::dynamic_pointer_cast<curve::Circle>(it), temp) circles.emplace_back(temp);
		for (const auto& it : circles) if (it.use_count() != 2) std::cout << std::endl << "Pointers are not shared with figure container" << std::endl;

		std::sort(circles.begin(), circles.end(),
			[](const auto& frs, const auto& scn) {
				return frs->getRadius() < scn->getRadius();
			});

		std::cout << std::endl << "Sorted container of circles:" << std::endl;;
		std::for_each(circles.begin(), circles.end(), [&t](const std::shared_ptr<curve::Circle>& shape)
			{
				std::cout << shape->getName() << " : Value : " <<
				shape->getPoint(t) << ": Derivative : " <<
				shape->getDerivative(t) << std::endl;
			});

		auto sum = std::accumulate(circles.begin(), circles.end(), .0, [](double sum, std::shared_ptr<curve::Circle>& arg)
			{
				return sum + arg->getRadius();
			});
		std::cout << std::endl << "Sum of radii : " << sum << std::endl;

	}
	catch (const std::invalid_argument& exc) {

		std::cerr << exc.what() << std::endl;
	}
	catch (const std::exception&)
	{
		std::cerr << "Standart exception" << std::endl;
	}
	catch (...)
	{
		std::cerr << "Non - standart exception" << std::endl;
	}
	return 0;
}