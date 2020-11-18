/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:25:38 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 14:28:42 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(void)
{
}

Victim::Victim(std::string name):
	_name(name)
{
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &other):
	_name(other._name)	
{
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

Victim&
Victim::operator=(const Victim &other)
{
	if (this != &other)
		this->_name = other._name;
	return (*this);
}

void
Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

const std::string&
Victim::getName(void) const
{
	return (this->_name);
}

std::ostream&
operator <<(std::ostream &stream, Victim &victim)
{
	return (stream << "I'm " << victim.getName() << " and I like otters!" << std::endl);
}
