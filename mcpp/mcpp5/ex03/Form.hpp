/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:46:56 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 19:46:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
class Bureaucrat ;
# include "Bureaucrat.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Form
{
	private:
		Form();
		
		bool _signed;
		std::string const _name;
		std::string const _target;
		const int _signGrade;
		const int _execGrade;
		
		int checkGrade(int grade);

	public:
		Form(std::string const name, std::string const target, int signGrade, int execGrade);
		Form(const Form &other);

		~Form();

		Form& operator=(const Form &other);

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};
		class UnsignedFormException: public std::exception {
			virtual const char* what() const throw();
		};

		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;


		const std::string & getName() const;
		const std::string & getTarget() const;
		bool isSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
};

std::ostream& operator<<(std::ostream &stream, const Form &form);

#endif