/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:24:54 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 19:48:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat boss("boss", 1);
	std::cout << boss << std::endl;
	Bureaucrat michel("michel", 25);
	std::cout << michel << std::endl;

	ShrubberyCreationForm *shrub = new ShrubberyCreationForm("home");
	std::cout << *shrub << std::endl;
	shrub->beSigned(boss);
	shrub->execute(michel);

	PresidentialPardonForm *pres = new PresidentialPardonForm("michel");
	std::cout << *pres << std::endl;
	boss.signForm(*pres);
	pres->execute(boss);

	RobotomyRequestForm *robot = new RobotomyRequestForm("Bender");
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

	std::cout << "---" << std::endl;

	try
	{
		RobotomyRequestForm robot = RobotomyRequestForm("Bender");
		std::cout << robot << std::endl;
		robot.execute(boss);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("michel");
		std::cout << pres << std::endl;
		boss.signForm(pres);
		pres.execute(michel);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("michel");
		std::cout << pres << std::endl;
		boss.signForm(pres);
		michel.executeForm(pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete robot;

	return (0);
}