#include "../include/Vector.hpp"

int main(void)
{
	Vector<float> a({1.0f, 1.0f});
	Vector<float> b({1.0f, 1.0f});
	std::cout << angle_cos(a, b) << std::endl;

	Vector<float> c({1.0f, 0.0f});
	Vector<float> d({0.0f, 1.0f});
	std::cout << angle_cos(c, d) << std::endl;

	Vector<float> e({-1.0f, 1.0f});
	Vector<float> f({1.0f, -1.0f});
	std::cout << angle_cos(e, f) << std::endl;

	Vector<float> g({2.0f, 1.0f});
	Vector<float> h({4.0f, 2.0f});
	std::cout << angle_cos(g, h) << std::endl;

	Vector<float> i({1.0f, 2.0f, 3.0f});
	Vector<float> j({4.0f, 5.0f, 6.0f});
	std::cout << angle_cos(i, j) << std::endl;

	return (0);
}