/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:26:52 by memartin          #+#    #+#             */
/*   Updated: 2020/11/22 12:32:10 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade):
	_name(name),
	_grade(grade)
{
	this->_grade = checkGrade(this->_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	this->operator=(other);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&
Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = this->checkGrade(other._grade);
	}
	return (*this);
}

int
Bureaucrat::checkGrade(int grade)
{
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	return (grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: Grade too Low";
}

void
Bureaucrat::incrementGrade()
{
	this->_grade = checkGrade(this->_grade - 1);
}

void
Bureaucrat::decrementGrade()
{
	this->_grade = checkGrade(this->_grade + 1);
}

int
Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string&
Bureaucrat::getName() const
{
	return (this->_name);
}

std::ostream&
operator<<(std::ostream& stream, const Bureaucrat &bureaucrat)
{
	return(stream << bureaucrat.getName() 
			<< ", buraucrat grade "
			<< bureaucrat.getGrade() << std::endl);
}