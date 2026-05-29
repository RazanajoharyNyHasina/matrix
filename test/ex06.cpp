#include "../include/Vector.hpp"

int main(void)
{
	Vector<float> a({0.0f, 0.0f, 1.0f});
	Vector<float> b({1.0f, 0.0f, 0.0f});
	std::cout << cross_product(a, b) << std::endl;
	std::cout << std::endl;

	Vector<float> c({1.0f, 2.0f, 3.0f});
	Vector<float> d({4.0f, 5.0f, 6.0f});
	std::cout << cross_product(c, d) << std::endl;
	std::cout << std::endl;

	Vector<float> e({4.0f, 2.0f, -3.0f});
	Vector<float> f({-2.0f, -5.0f, 16.0f});
	std::cout << cross_product(e, f) << std::endl;
	std::cout << std::endl;
}