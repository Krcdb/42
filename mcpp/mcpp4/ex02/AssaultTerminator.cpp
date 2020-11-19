/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:45:22 by memartin          #+#    #+#             */
/*   Updated: 2020/11/19 18:12:34 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &other)
{
	std::cout << "* teleports from space *" << std::endl;
	this->operator =(other);
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back..." << std::endl;
}

AssaultTerminator& 
AssaultTerminator::operator=(const AssaultTerminator &other)
{
	(void)other;
	return (*this);
}

ISpaceMarine*
AssaultTerminator::clone() const
{
	return (new AssaultTerminator(*this));
}

void
AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void
AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void
AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}