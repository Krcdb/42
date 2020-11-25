/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:03:30 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 19:16:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base *creatClass()
{
	int nb = rand() % 3;

	if (nb == 0)
	{
		std::cout << "generate A" << std::endl;
		return (new A);
	}
	else if (nb == 1)
	{
		std::cout << "generate B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "generate C" << std::endl;
		return (new C);
	}
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C" << std::endl;
	else
		std::cout << "wrong class" << std::endl;
}

void identify_from_reference(Base &p)
{
	identify_from_pointer(&p);
}