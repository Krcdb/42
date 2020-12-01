/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:15:16 by user42            #+#    #+#             */
/*   Updated: 2020/12/01 14:16:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <queue>
# include <deque>
# include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>(){};
		MutantStack(const MutantStack<T> &other): std::stack<T>(other) {};

		~MutantStack() {};

		MutantStack<T>& operator=(const MutantStack<T> &other)
		{
			std::stack<T>::operator =(other);
		}
		
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return std::stack<T>::c.begin();
		}
		iterator end()
		{
			return std::stack<T>::c.end();
		}
};

#endif