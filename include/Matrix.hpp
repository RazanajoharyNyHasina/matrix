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
	    : cols(c), rows(r), data(values) {};

	Matrix(size_t r, size_t c)
	{
		data.resize(r * c);
		rows = r;
		cols = c;
	}

	Matrix(const Matrix<float> &other)
	{
		*this = other;
	}

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

	size_t get_rows_size(void) const
	{
		return (rows);
	}

	size_t get_cols_size(void) const
	{
		return (cols);
	}

	bool is_square(void) const
	{
		return rows == cols;
	}

	K &at(size_t row, size_t col)
	{
		return data[col * rows + row];
	}

	void assign_at(size_t row, size_t col, K value)
	{
		data[col * rows + row] = value;
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

	for (size_t col = 0; col < matrix.get_cols_size(); col++)
	{
		stream << "{";

		for (size_t row = 0; row < matrix.get_rows_size(); row++)
		{
			stream << matrix.at(row, col);

			if (row != matrix.get_rows_size() - 1)
				stream << ",";
		}

		stream << "}\n";
	}

	return stream;
}

template <typename K>
Matrix<K> linear_interpolation(const Matrix<K> &a, const Matrix<K> &b, const float t)
{
	const size_t row_dimension = a.get_rows_size();
	const size_t col_dimension = a.get_cols_size();
	Matrix<K> result(row_dimension, col_dimension);

	for (size_t i_r = 0; i_r < row_dimension; i_r++)
	{
		for (size_t i_c = 0; i_c < col_dimension; i_c++)
		{
			result.assign_at(i_r, i_c, std::fma(b.at(i_r, i_c) - a.at(i_r, i_c), t, a.at(i_r, i_c)));
		}
	}
	return (result);
}

#endif