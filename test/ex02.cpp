#include "../include/Vector.hpp"
#include "../include/Matrix.hpp"

int main(void)
{
	// println !("{}", lerp(0., 1., 0.));
	// 0.0
	std::cout << linear_interpolation(0.0, 1.0, 0.0) << std::endl;

	// println !("{}", lerp(0., 1., 1.));
	// 1.0
	std::cout << linear_interpolation(0.0, 1.0, 1.0) << std::endl;

	// println !("{}", lerp(0., 1., 0.5));
	// 0.5
	std::cout << linear_interpolation(0.0, 1.0, 0.5) << std::endl;

	// println !("{}", lerp(21., 42., 0.3));
	// 27.3
	std::cout << linear_interpolation(21.0, 42.0, 0.3) << std::endl;

	// println !("{}", lerp(Vector::from([ 2., 1. ]), Vector::from(4., 2.), 0.3));
	// [2.6]
	// [1.3]
	std::cout << linear_interpolation((Vector<float>){2.0, 1.0}, (Vector<float>){4.0, 2.0}, 0.3) << std::endl;

	// println !("{}", lerp(Matrix::from([ [ 2., 1. ], [ 3., 4. ] ]), Matrix::from([[20.,10.], [ 30., 40. ] ]), 0.5));
	// [[11., 5.5]
	// [16.5, 22.]]

	Matrix<float> m1(2, 2, {2.0f, 1.0f, 3.0f, 4.0f});
	Matrix<float> m2(2, 2, {20.0f, 10.0f, 30.0f, 40.0f});

	std::cout << linear_interpolation(m1, m2, 0.5) << std::endl;
	return (0);
}