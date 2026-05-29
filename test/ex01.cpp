#include "../include/Vector.hpp"

int main(void)
{
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

	return (0);
}