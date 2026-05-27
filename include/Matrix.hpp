#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <vector>
#include <cstddef>
#include <iostream>

template <typename K>
class Matrix
{
private:
	size_t cols;
	size_t rows;
	std::vector<K> data;

public:
	Matrix(size_t r, size_t c, std::initializer_list<K> values)
	    : cols(c), rows(r), data(values) {}

	Matrix<K> &operator=(const Matrix &other)
	{
		if (this != &other)
		{
			data = other.data;
			cols = other.cols;
			rows = other.rows;
		}

		return *this;
	}

	bool is_square(void) const
	{
		return rows == cols;
	}

	K &at(size_t row, size_t col)
	{
		return data[col * rows + row];
	}

	const K &at(size_t row, size_t col) const
	{
		return data[col * rows + row];
	}

	template <typename T>
	friend std::ostream &operator<<(std::ostream &stream, const Matrix<T> &matrix);

	~Matrix(void) {}
};

template <typename K>
std::ostream &operator<<(std::ostream &stream, const Matrix<K> &matrix)
{
	stream << "Matrix:\n";

	for (size_t i = 0; i < matrix.rows; i++)
	{
		stream << "{";

		for (size_t j = 0; j < matrix.cols; j++)
		{
			stream << matrix.at(i, j);

			if (j != matrix.cols - 1)
				stream << ",";
		}

		stream << "}\n";
	}

	return stream;
}

#endif