/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:21:51 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 14:19:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <cstdlib>
#include <list>
#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack():
	std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other): 
	std::stack<T>(other)
{}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T>&
MutantStack<T>::operator=(const MutantStack<T> &other)
{
	std::stack<T>::operator =(other);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}