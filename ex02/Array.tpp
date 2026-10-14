/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:15:51 by afournie          #+#    #+#             */
/*   Updated: 2026/10/14 14:29:21 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(Array const &ref) : _data(NULL), _size(0) { *this = ref; }

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* tmp = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			tmp[i] = other._data[i];
		delete[] _data;
		_data = tmp;
		_size = other._size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array() { delete[] _data; }

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBoundsException();
	return _data[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw OutOfBoundsException();
	return _data[i];
}

template <typename T>
unsigned int Array<T>::size() const { return _size; }

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array: index out of bounds";
}

