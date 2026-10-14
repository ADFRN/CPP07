/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:15:54 by afournie          #+#    #+#             */
/*   Updated: 2026/10/14 15:03:39 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <ctime>

template <typename T>
class	Array
{
	private:
		unsigned int	_size;
		T*				_data;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const &ref);
		Array& operator=(const Array& other);

		const T&	operator[](unsigned int i) const;
		T&			operator[](unsigned int i);

		unsigned int size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

		~Array();
};

#include "Array.tpp"

#endif
