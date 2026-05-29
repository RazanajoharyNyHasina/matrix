#include "../include/Vector.hpp"

int main(void)
{
	Vector<float_t> a({0.0f, 0.0f, 0.0f});
	std::cout << norm_1(a) << std::endl;
	std::cout << norm(a) << std::endl;
	std::cout << norm_inf(a) << std::endl;
	std::cout << "\n";

	Vector<float_t> b({1.0f, 2.0f, 3.0f});
	std::cout << norm_1(b) << std::endl;
	std::cout << norm(b) << std::endl;
	std::cout << norm_inf(b) << std::endl;
	std::cout << "\n";

	Vector<float_t> c({-1.0f, -2.0f});
	std::cout << norm_1(c) << std::endl;
	std::cout << norm(c) << std::endl;
	std::cout << norm_inf(c) << std::endl;

	return (0);
}