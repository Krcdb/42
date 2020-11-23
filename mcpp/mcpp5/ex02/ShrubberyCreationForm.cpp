/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:18:42 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 19:47:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

static const char *ASCII_TREE = ""
"          &&& &&  & &&				\n"
"      && &/&&||& ()|/ @, &&		\n"
"      &&&(/&/&||/& /_/)_&/_&		\n"
"   &() &&&&|()|/&/& '% & () 		\n"
"  &_&/&&_/ |& |&&/&__%_/_& &&		\n"
"&&   && & &| &| /& & % ()& /&&		\n"
" ()&_---()&|&//&&-&&--%---()~		\n"
"     &&      |||					\n"
"             |||					\n"
"             |||					\n"
"             |||					\n"
"       , -=-~  .-^- _				\n"
"ejm97         `					\n";

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
	Form("Shrubbery Creation", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	Form(other)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char* 
ShrubberyCreationForm::TargetFileOpenException::what() const throw()
{
	return "ShrubberyCreationFormException: Cannot open file";
}

const char* 
ShrubberyCreationForm::WriteException::what() const throw()
{
	return "ShrubberyCreationFormException: Error while writing to the file";
}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	(void)other;
	return (*this);
}

void 
ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::ofstream outfile;
	
	outfile.open((this->getTarget() + "_shrubbery"), std::ios::out | std::ios::app);

	if (!outfile.is_open() || outfile.bad())
		throw ShrubberyCreationForm::TargetFileOpenException();
	
	outfile << ASCII_TREE;
	if (outfile.bad())
	{
		outfile << std::endl;
		outfile.close();
		throw ShrubberyCreationForm::WriteException();
	}
	outfile << std::endl;
	outfile.close();
}