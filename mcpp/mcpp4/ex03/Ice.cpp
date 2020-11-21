/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:31:57 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 10:52:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():
	AMateria("ice")
{
}

Ice::Ice(const Ice &other):
    AMateria(other)
{
}

Ice::~Ice()
{
}

Ice&
Ice::operator=(const Ice &other)
{
    AMateria::operator=(other);
    return (*this);
}

Ice*
Ice::clone() const
{
    return (new Ice(*this));
}

void
Ice::use(ICharacter &target)
{
	AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}