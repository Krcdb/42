/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:26:54 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 14:14:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "top: " << mstack.top() << std::endl;

	std::cout << "size before pop: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "size after pop: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "size after pop: " << mstack.size() << std::endl;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "stack content: " << std::endl;
	while (it != ite)
	{
		std::cout << ">>> " << *it << std::endl;
		++it;
	}

	it = mstack.begin();
	ite = mstack.end();

	std::cout << "stack reversed content: " << std::endl;
	while (it != ite)
	{
		--ite;
		std::cout << ">>> " << *ite << std::endl;
	}

	std::stack<int> s(mstack);
	std::cout << "copying: are same size? "
	        << (s.size() == mstack.size() ? "yes" : "no")
	        << " (supposed to be yes)" << std::endl;
	return (0);
}