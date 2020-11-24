/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:24:54 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 15:13:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat boss("boss", 1);
	std::cout << boss << std::endl;
	Bureaucrat michel("michel", 25);
	std::cout << michel << std::endl;
	Intern intern;

	Form *wrongFrom;
	std::cout << "\n --wrong form creation\n" << std::endl;
	try
	{
		wrongFrom = intern.makeForm("wrong form", "target");
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Form *shrub = intern.makeForm("shrubbery creation", "home");
	std::cout << *shrub << std::endl;
	shrub->beSigned(boss);
	shrub->execute(michel);

	Form *pres = intern.makeForm("presidential pardon", "michel");
	std::cout << *pres << std::endl;
	boss.signForm(*pres);
	pres->execute(boss);

	Form *robot = intern.makeForm("robotomy request", "Bender");
	std::cout << *robot << std::endl;
	robot->beSigned(boss);
	robot->execute(michel);
	michel.executeForm(*robot);
	michel.executeForm(*robot);

	std::cout << "---" << std::endl;

	try
	{
		michel.executeForm(*pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
//
//	delete shrub;
//	delete pres;
//	delete robot;
//
	return (0);
}