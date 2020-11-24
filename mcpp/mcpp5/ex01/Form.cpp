/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:04:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 12:20:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int signGrade, int execGrade):
	_signed(false),
	_name(name),
	_signGrade(checkGrade(signGrade)),
	_execGrade(checkGrade(execGrade))
{
}

Form::Form(const Form &other):
	_signed(other._signed),
	_name(other._name),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
}

Form::~Form()
{
}

Form&
Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "FormException: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "FormException: Grade too Low";
}

int
Form::checkGrade(int grade)
{
	if (grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	return (grade);
}

void
Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

bool
Form::isSigned() const
{
	return (this->_signed);
}

const std::string&
Form::getName() const
{
	return (this->_name);
}

int
Form::getSignGrade() const
{
	return (this->_signGrade);
}

int
Form::getExecGrade() const
{
	return (this->_execGrade);
}

std::ostream&
operator<<(std::ostream &stream, const Form &form)
{
	return (stream << "Form named " << form.getName()
			<< " : sign grade(" << form.getSignGrade()
			<< ") | exec grade(" << form.getExecGrade()
			<< ") | is signed : "
			<< ((form.isSigned()) ? "yes" : "no") << std::endl);
}