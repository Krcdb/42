/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:26:52 by memartin          #+#    #+#             */
/*   Updated: 2020/11/23 19:43:11 by user42           ###   ########.fr       */
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

void
Bureaucrat::signForm(Form &form)
{
	bool succes = false;

	if (!form.isSigned())
	{
		try
		{
			form.beSigned(*this);
			succes = true;
		}
		catch(std::exception const &e)
		{
		}
	}
	std::cout << this->_name;
	if (succes)
		std::cout << " succesfully signs " << form.getName() << std::endl;
	else
		std::cout << " can't signs " << form.getName() << " because "
			<< (form.isSigned() ? "it was already signed" : "his grade is too low")
			<< std::endl;
}

void 
Bureaucrat::executeForm(Form const &form) const
{
	if (!form.isSigned())
	{
		std::cout << *this << " cannot execute " << form
				<< " because the form is unsigned." << std::endl;
	}
	else if (form.getExecGrade() < this->_grade)
	{
		std::cout << *this << " cannot execute " << form
				<< " because it's grade is too low." << std::endl;
	}
	else
	{
		std::cout << *this << " executes " << form << std::endl;
	}
	form.execute(*this);
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
	return (stream << bureaucrat.getName() 
			<< ", buraucrat grade "
			<< bureaucrat.getGrade() << std::endl);
}