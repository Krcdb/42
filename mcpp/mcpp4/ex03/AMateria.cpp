/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:10:02 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 14:30:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type):
    _type(type),
    _xp(0)
{
}

AMateria::AMateria(const AMateria &other):
    _type(other._type),
    _xp(other._xp)
{
}

AMateria::~AMateria()
{
}

AMateria&
AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        this->_xp = other._xp;
        this->_type = other._type;
    }
    return (*this);
}

void
AMateria::use(ICharacter &target)
{
    (void)target;
    this->_xp += 10;
}

const std::string&
AMateria::getType() const
{
    return (this->_type);
}

unsigned int
AMateria::getXP() const
{
    return (this->_xp);
}