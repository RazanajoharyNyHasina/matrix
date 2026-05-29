#include "../include/Vector.hpp"

int main(void)
{
	Vector<float> a({0.0f, 0.0f});
	Vector<float> b({1.0f, 1.0f});
	std::cout << dot(a, b) << std::endl;

	Vector<float> c({1.0f, 1.0f});
	Vector<float> d({1.0f, 1.0f});
	std::cout << dot(c, d) << std::endl;

	Vector<float> e({-1.0f, 6.0f});
	Vector<float> f({3.0f, 2.0f});
	std::cout << dot(e, f) << std::endl;
	return (0);
}