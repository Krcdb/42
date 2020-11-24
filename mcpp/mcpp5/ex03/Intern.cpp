/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:55:53 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 15:11:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	this->operator=(other);
}

Intern::~Intern()
{
}

Intern&
Intern::operator=(const Intern &other)
{
	(void)other;

	return (*this);
}

const char* Intern::FormDoesNotExistException::what() const throw()
{
	return "InternException: Form does not exist";
}

Form*
Intern::creatPresidentialPardonForm(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

Form*
Intern::creatRobotomyRequestForm(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

Form*
Intern::creatShrubberyCreationForm(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}

Form*
Intern::makeForm(const std::string &name, const std::string target)
{
	Form* (Intern::*fptr[NB_FORM])(const std::string target) = {
		&Intern::creatPresidentialPardonForm,
		&Intern::creatRobotomyRequestForm,
		&Intern::creatShrubberyCreationForm
	};

	std::string formName[NB_FORM] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	for (int idx = 0; idx < NB_FORM; idx++)
	{
		if (formName[idx] == name)
		{
			std::cout << "Intern create " << name << std::endl;
			return (((this->*fptr[idx])(target)));
		}
	}
	throw Intern::FormDoesNotExistException();
}