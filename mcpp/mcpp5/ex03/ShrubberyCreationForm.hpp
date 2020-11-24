/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:16:12 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 11:39:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	
	virtual ~ShrubberyCreationForm();

	class TargetFileOpenException: public std::exception {
		virtual const char* what() const throw();
	};
	class WriteException: public std::exception {
		virtual const char* what() const throw();
	};

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

	void execute(Bureaucrat const &executor) const;
	Form *creatForm(std::string const &target);
};

#endif