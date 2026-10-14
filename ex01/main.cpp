/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:44:05 by afournie          #+#    #+#             */
/*   Updated: 2026/09/28 15:45:52 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void increment(T &x)
{
	x++;
}

template <typename T>
void print(const T &x)
{
	std::cout << x << " ";
}

void toUpper(std::string &s)
{
	for (std::size_t i = 0; i < s.length(); i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
}

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5};
	std::cout << "before:    ";
	::iter(nums, 5, print<int>);
	std::cout << std::endl;

	::iter(nums, 5, increment<int>);
	std::cout << "increment: ";
	::iter(nums, 5, print<int>);
	std::cout << std::endl;

	const int fixed[] = {10, 20, 30};
	std::cout << "const arr: ";
	::iter(fixed, 3, print<int>);
	std::cout << std::endl;

	double ds[] = {1.5, 2.5, 3.5};
	::iter(ds, 3, increment<double>);
	std::cout << "doubles:   ";
	::iter(ds, 3, print<double>);
	std::cout << std::endl;

	std::string words[] = {"hello", "world", "iter"};
	::iter(words, 3, toUpper);
	std::cout << "strings:   ";
	::iter(words, 3, print<std::string>);
	std::cout << std::endl;

	return 0;
}
