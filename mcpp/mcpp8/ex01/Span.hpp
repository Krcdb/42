/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:05:09 by user42            #+#    #+#             */
/*   Updated: 2020/11/29 15:52:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <vector>

class Span
{
	private:
		Span();
		unsigned int		_n;
		std::vector<int>	_vector;

	public:
		Span(unsigned int n);
		Span(const Span &other);
		~Span();

		Span& operator=(const Span &other);

		void	addNumber(int nb);
		void	addNumber(int from, int to);
		void	addNumberRand(int from, int to, int nb);

		int		shortestSpan();
		int		longestSpan();

		void	display();

		class CapacityReach: public std::exception {
			virtual const char* what() const throw();
		};
		class BadArgument: public std::exception {
			virtual const char* what() const throw();
		};
		class NeedAtLeastTwo: public std::exception {
			virtual const char* what() const throw();
		};
};

#endif