/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:48:29 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 10:49:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():
    AMateria("cure")
{
}

Cure::Cure(const Cure &other):
    AMateria(other)
{
}

Cure::~Cure()
{
}

Cure&
Cure::operator=(const Cure &other)
{
    AMateria::operator=(other);
    return (*this);
}

Cure*
Cure::clone() const
{
    return (new Cure(*this));
}

void
Cure::use(ICharacter &target)
{
	AMateria::use(target);
    std::cout << "* heals "<< target.getName() << "’s wounds *" << std::endl;
}