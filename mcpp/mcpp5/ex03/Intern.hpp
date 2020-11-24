/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:38:30 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 15:08:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
# define INTER_HPP

# include <iostream>
# include <string>

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define NB_FORM 3

class Intern
{
	private:
  		Form* creatPresidentialPardonForm(const std::string target);
   		Form* creatRobotomyRequestForm(const std::string target);
   		Form* creatShrubberyCreationForm(const std::string target);	

	public:
		Intern();
		Intern(const Intern &other);

		~Intern();

		Intern& operator=(const Intern &other);

		Form *makeForm(const std::string &name, const std::string target);

		class FormDoesNotExistException: public std::exception {
			virtual const char* what() const throw();
		};
};

#endif