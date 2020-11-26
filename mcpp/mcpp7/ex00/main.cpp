/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:43:05 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 16:25:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main(void)
{
	int a = 42;
	int b = 12;

	std::cout << "a : " << a << " | b : " << b << std::endl;
	::swap(a, b);
	std::cout << "a : " << a << " | b : " << b << std::endl;
	std::cout << "min (a, b) : " << ::min(a, b) << std::endl;
	std::cout << "max (a, b) : " << ::max(a, b) << std::endl;


	std::string c = "str1";
	std::string d = "str2";

	std::cout << "c : " << c << " | d : " << d << std::endl;
	::swap(c, d);
	std::cout << "c : " << c << " | d : " << d << std::endl;
	std::cout << "min (c, d) : " << ::min(c, d) << std::endl;
	std::cout << "max (c, d) : " << ::max(c, d) << std::endl;
	return (0);
}