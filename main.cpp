#include "./include/Vector.hpp"
#include "./include/Matrix.hpp"
#include <iostream>

int main(void)
{
	Vector<float> v = {2.0, 5.0};
	Vector<float> t = {2.0, 5.0};
	Matrix<float> m(3, 3, {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0});

	std::cout << v << std::endl;
	std::cout << m << std::endl;

	std::cout << "+: " << v + t << std::endl;

	Vector<float> subtracted = v - t;

	std::cout << "-: " << subtracted << std::endl;

	subtracted += Vector<float>({10.0, 20.0});
	std::cout << "+=: " << subtracted << std::endl;

	subtracted -= Vector<float>({5.0, 7.0});
	std::cout << "*: " << v * 2.0 << std::endl;

	std::cout << "-=: " << subtracted << std::endl;

	subtracted *= 5;
	std::cout << "*=: " << subtracted << std::endl;
}