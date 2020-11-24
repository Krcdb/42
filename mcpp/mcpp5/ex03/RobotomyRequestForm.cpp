/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:10:21 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 11:40:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
	Form("Robotomy Request", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):
	Form(other)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&
RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	(void)other;
	return (*this);
}

void 
RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << "* make some drilling noises *" << std::endl;
	if ((rand() % 100) >= 50)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "You failed looser" << std::endl;
}

Form*
RobotomyRequestForm::creatForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}