/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:22:32 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 18:14:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat michel("michel", 100);
	std::cout << michel;
	Bureaucrat boss("boss", 1);
	std::cout << boss;
	
	Form form99("form99", 99, 50);
	std::cout << form99;
	std::cout << "\n --try low grade--\n" << std::endl;
	try
	{
		form99.beSigned(michel);
	}
	catch(std::exception const &e)	
	{
		std::cerr << e.what() << std::endl;
	}	
	std::cout << form99;
	std::cout << "\n --increment grade and sign--\n" << std::endl;
	michel.incrementGrade();
	std::cout << michel;
	try
	{
		form99.beSigned(michel);
	}
	catch(std::exception const &e)	
	{
		std::cerr << e.what() << std::endl;
	}	
	std::cout << form99;
	std::cout << "\n --try to sign the form again--\n" << std::endl;
	try
	{
		michel.signForm(form99);
	}
	catch(std::exception const &e)	
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << form99;

	std::cout << "\n --create wrong form--\n" << std::endl;
	try
	{
		Form highSign("plop", 0, 50);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form lowSign("plop", 456, 50);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form highExec("plop", 123, 0);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form lowExec("plop", 123, 456);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
}