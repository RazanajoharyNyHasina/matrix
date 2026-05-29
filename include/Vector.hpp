#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <vector>
#include <cstddef>
#include <iostream>
#include <math.h>

template <typename K>
class Vector
{
private:
	std::vector<K> data;

public:
	Vector(std::initializer_list<K> values) : data(values) {}

	Vector(const Vector<K> &other)
	{
		operator=(other);
	}

	Vector(const size_t &size)
	{
		data.resize(size);
	}

	Vector<K> &operator=(const Vector &other)
	{
		if (this != &other)
			data = other.data;
		return (*this);
	}

	size_t size(void) const
	{
		return data.size();
	}

	K &operator[](size_t index)
	{
		return data[index];
	}

	const K &operator[](size_t index) const
	{
		return data[index];
	}

	Vector<K> operator+(const Vector<K> &to_add) const
	{
		Vector<K> result = *this;

		for (size_t i = 0; i < to_add.size(); i++)
			result[i] += to_add[i];
		return (result);
	}

	Vector<K> operator-(const Vector<K> &to_subtract) const
	{
		Vector<K> result = *this;

		for (size_t i = 0; i < to_subtract.size(); i++)
			result[i] -= to_subtract[i];
		return (result);
	}

	Vector<K> operator*(const K &scale) const
	{
		Vector<K> result = *this;

		for (size_t i = 0; i < size(); i++)
			result[i] *= scale;
		return (result);
	}

	Vector<K> &operator+=(const Vector<K> &to_add)
	{
		for (size_t i = 0; i < to_add.size(); i++)
			data[i] += to_add[i];
		return (*this);
	}

	Vector<K> &operator-=(const Vector<K> &to_subtract)
	{
		for (size_t i = 0; i < to_subtract.size(); i++)
			data[i] -= to_subtract[i];
		return (*this);
	}

	Vector<K> &operator*=(const K &scale)
	{
		for (size_t i = 0; i < size(); i++)
			data[i] *= scale;
		return (*this);
	}

	template <typename T>
	friend std::ostream &operator<<(std::ostream &stream, const Vector<T> &vector);

	~Vector(void) {};
};

template <typename K>
std::ostream &operator<<(std::ostream &stream, const Vector<K> &vector)
{
	stream << "Vector: {";

	for (typename std::vector<K>::const_iterator i = vector.data.begin();
	     i != vector.data.end();
	     ++i)
	{
		stream << *i;

		if (i != vector.data.end() - 1)
			stream << ",";
	}

	stream << "}";

	return stream;
}

template <typename K>
Vector<K> linear_combination(const std::initializer_list<Vector<K>> u, const K *coefs)
{
	const size_t dimension = u.begin()->size();
	Vector<K> result(dimension);

	size_t vec_i = 0;

	for (const Vector<K> &current_vector : u)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			result[j] = std::fma(current_vector[j], coefs[vec_i], result[j]);
		}
		vec_i++;
	}

	return result;
}

template <typename K>
Vector<K> linear_interpolation(const Vector<K> &a, const Vector<K> &b, const float t)
{
	const size_t dimension = a.size();
	Vector<K> result(dimension);

	for (size_t i = 0; i < dimension; i++)
	{
		result[i] = std::fma(b[i] - a[i], t, a[i]);
	}
	return (result);
}

template <typename K>
K linear_interpolation(const K &a, const K &b, const float t)
{
	return (std::fma(b - a, t, a));
}

#endif
