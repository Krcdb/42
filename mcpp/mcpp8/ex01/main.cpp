/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:49:50 by user42            #+#    #+#             */
/*   Updated: 2020/11/29 17:06:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	srand(time(NULL));

	std::cout << std::endl <<"--- Exceptoion ---\n" << std::endl;

	Span excep(3);
	try
	{
		excep.shortestSpan();
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		excep.longestSpan();
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	try
	{
		excep.addNumber(0, 100);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		excep.addNumber(1000, 100);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	Span sp = Span(5);

	std::cout << std::endl <<"--- 42 TEST ---\n" << std::endl;
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	sp.display();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl <<"--- Rand 10 ---\n" << std::endl;
	Span random10(10);
	random10.addNumberRand(-1000, 1000, 10);
	random10.display();
	std::cout << random10.shortestSpan() << std::endl;
	std::cout << random10.longestSpan() << std::endl;

	std::cout << std::endl <<"--- Rand 1000 ---\n" << std::endl;
	Span random1000(1000);
	random1000.addNumberRand(-10000000, 10000000, 1000);
	//random1000.display();
	std::cout << random1000.shortestSpan() << std::endl;
	std::cout << random1000.longestSpan() << std::endl;
}