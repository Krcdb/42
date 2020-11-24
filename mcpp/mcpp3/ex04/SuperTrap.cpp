/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:45:56 by memartin          #+#    #+#             */
/*   Updated: 2020/11/24 15:44:46 by user42           ###   ########.fr       */
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

void
SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
}

void
SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}
