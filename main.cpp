#include "./include/Vector.hpp"
#include "./include/Matrix.hpp"
#include <iostream>

int main(void)
{
	Vector<float> v = {2.0, 0.0};
	Matrix<float> m(3, 3, {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0});

	std::cout << v << std::endl;
	std::cout << m << std::endl;
}