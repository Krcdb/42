/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 11:57:45 by memartin          #+#    #+#             */
/*   Updated: 2020/11/22 12:25:11 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BURAUCRAT_HPP
# define BURAUCRAT_HPP

# include <iostream>
# include <string>
class Form ;
# include "Form.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
	private:
		Bureaucrat();

		std::string _name;
		int _grade;

		int checkGrade(int grade);
	
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &other);

		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat &other);

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};

		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form &form);

		int getGrade(void) const;
		std::string const & getName(void) const;
};

std::ostream& operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

#endif