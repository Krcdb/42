/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:52:12 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 14:32:41 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)
{
}

Sorcerer::Sorcerer(std::string name, std::string title):
	_name(name),
	_title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &other):
	_name(other._name),
	_title(other._title)
{
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer&
Sorcerer::operator=(const Sorcerer &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_title = other._title;
	}
	return (*this);
}

void
Sorcerer::polymorph(const Victim &victim) const
{
	victim.getPolymorphed();
}

const std::string&
Sorcerer::getName(void) const
{
	return (this->_name);
}

const std::string&
Sorcerer::getTitle(void) const
{
	return (this->_title);
}

std::ostream&
operator <<(std::ostream &stream, Sorcerer &sorcerer)
{
	return (stream << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and i like ponies!" << std::endl);
}
