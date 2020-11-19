/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:45:22 by memartin          #+#    #+#             */
/*   Updated: 2020/11/19 19:03:33 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for batlle!" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &other)
{
	std::cout << "Tactical Marine ready for batlle!" << std::endl;
	this->operator =(other);
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine& 
TacticalMarine::operator=(const TacticalMarine &other)
{
	(void)other;
	return (*this);
}

ISpaceMarine*
TacticalMarine::clone() const
{
	return (new TacticalMarine(*this));
}

void
TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void
TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void
TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}