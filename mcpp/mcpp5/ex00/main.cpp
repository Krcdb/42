/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:25:17 by memartin          #+#    #+#             */
/*   Updated: 2020/11/22 12:34:20 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat michel("michel", 100);
	std::cout << michel << std::endl;
	michel.incrementGrade();
	std::cout << michel << std::endl;
	michel.decrementGrade();
	std::cout << michel << std::endl;

	try
	{
		Bureaucrat patrick("patrick", 0);
		std::cout << patrick << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat patrick("patrick", 1000);
		std::cout << patrick << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat patrick("patrick", 1);
		std::cout << patrick << std::endl;
		patrick.incrementGrade();
		std::cout << patrick << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat patrick("patrick", 150);
		std::cout << patrick << std::endl;
		patrick.decrementGrade();
		std::cout << patrick << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}