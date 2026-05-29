#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <vector>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <algorithm>

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

	typename std::vector<K>::iterator begin(void)
	{
		return (data.begin());
	}

	typename std::vector<K>::iterator end(void)
	{
		return (data.end());
	}

	typename std::vector<K>::const_iterator begin(void) const
	{
		return (data.cbegin());
	}

	typename std::vector<K>::const_iterator end(void) const
	{
		return (data.cend());
	}

	template <typename T>
	friend std::ostream &operator<<(std::ostream &stream, const Vector<T> &vector);

	~Vector(void) {};
};

float fast_sqrt(float number)
{
	int i;
	float x, y;
	x = number * 0.5;
	y = number;
	i = *(int *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (1.5 - (x * y * y));
	y = y * (1.5 - (x * y * y));

	return number * y;
}

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

template <typename K>
K dot(const Vector<K> &a, const Vector<K> &b)
{
	const size_t dimension = a.size();
	K accumulation{};

	for (size_t i = 0; i < dimension; i++)
		accumulation = std::fma(a[i], b[i], accumulation);

	return (accumulation);
}

template <typename K>
float norm_1(const Vector<K> &v)
{
	float tmp = 0.0;

	for (const K &value : v)
		tmp += (value < 0) ? -value : value;

	return (tmp);
}

template <typename K>
float norm(const Vector<K> &v)
{
	float tmp = 0.0;

	for (const K &value : v)
		tmp = std::fma(value, value, tmp);

	return (fast_sqrt(tmp));
}

template <typename K>
float norm_inf(const Vector<K> &v)
{
	float tmp = 0.0;

	for (const K &value : v)
		tmp = std::max((value < 0) ? -value : value, tmp);

	return (tmp);
}

template <typename K>
float angle_cos(const Vector<K> &a, const Vector<K> &b)
{
	float dot = 0.0;
	float norm_a = 0.0;
	float norm_b = 0.0;

	for (size_t i = 0; i < a.size(); i++)
	{
		dot = std::fma(a[i], b[i], dot);
		norm_a = std::fma(a[i], a[i], norm_a);
		norm_b = std::fma(b[i], b[i], norm_b);
	}

	if (norm_a < 1e-8f or norm_b < 1e-8f)
		return (0);
	return (dot / (fast_sqrt(norm_a) * fast_sqrt(norm_b)));
}

#endif