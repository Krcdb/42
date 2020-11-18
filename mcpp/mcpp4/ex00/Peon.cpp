/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:15:55 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 14:31:40 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon():
	Victim()
{
}

Peon::Peon(std::string name):
        Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &other):
        Victim(other)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}


Peon&
Peon::operator=(const Peon &other)
{
	Victim::operator =(other);

	return (*this);
}

void
Peon::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}

std::ostream&
operator <<(std::ostream &stream, Peon &peon)
{
	return (stream << "I'm " << peon.getName() << " and I like otters!" << std::endl);
}
