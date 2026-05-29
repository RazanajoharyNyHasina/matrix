#include "./include/Vector.hpp"
#include "./include/Matrix.hpp"

#include <iostream>
#include <vector>

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

	std::cout << "#== Linear Combination Test ======================\n";
	Vector<float> a({1.0, 0.0, 0.0});
	Vector<float> b({0.0, 1.0, 0.0});
	Vector<float> c({0.0, 0.0, 1.0});

	Vector<float> d({1.0, 2.0, 3.0});
	Vector<float> e({0.0, 10.0, -100.0});

	float data_linear_test_one[] = {10.0, -2.0, 0.5};
	Vector<float> linear_result_one = linear_combination({a, b, c}, data_linear_test_one);

	float data_linear_test_two[] = {10.0, -2.0};
	Vector<float> linear_result_two = linear_combination({d, e}, data_linear_test_two);

	std::cout << "Linear Combination Test One: " << linear_result_one << std::endl;
	std::cout << "Linear Combination Test Two: " << linear_result_two << std::endl;
}