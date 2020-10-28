/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:45:56 by memartin          #+#    #+#             */
/*   Updated: 2020/10/28 11:57:22 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void):
	ClapTrap("default", 100, 100, 120, 120, 1, 60, 20, 5),
	FragTrap(),
	NinjaTrap()
{
	say("SupBoy created !");
}

SuperTrap::SuperTrap(std::string name):
	ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5),
	FragTrap(),
	NinjaTrap()
{
	say("SupBoy created !");
}

SuperTrap::SuperTrap(const SuperTrap &other):
	ClapTrap(other),
	FragTrap(other),
	NinjaTrap(other)
{
	*this = other;
	say("copied !");
	say("This time it'll be awesome, I promise!");
}


SuperTrap::~SuperTrap()
{
	say("SupBoy destroyed !");
}

SuperTrap&
SuperTrap::operator =(const SuperTrap &other)
{
	FragTrap::operator =(other);
	NinjaTrap::operator =(other);

	say("assigned !");
	say("Recompiling my combat code!");
	return (*this);
}
