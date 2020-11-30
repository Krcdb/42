/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:15:16 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 14:20:20 by user42           ###   ########.fr       */
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

		MutantStack();
		MutantStack(const MutantStack<T> &other);

		~MutantStack();

		MutantStack<T>& operator=(const MutantStack<T> &other);
		
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

#endif