/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:25:50 by memartin          #+#    #+#             */
/*   Updated: 2020/11/24 15:51:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void):
	ClapTrap()
{
	say("NinjaBoy created !");
}

NinjaTrap::NinjaTrap(std::string name):
	ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5)
{
	say("NinjaBoy created !");
}

NinjaTrap::NinjaTrap(const NinjaTrap &other)
{
	*this = other;
	say("copied !");
	say("This time it'll be awesome, I promise!");
}


NinjaTrap::~NinjaTrap()
{
	say("NinjaBoy destroyed !");
}

NinjaTrap&
NinjaTrap::operator =(const NinjaTrap &other)
{
	ClapTrap::operator =(other);

	say("assigned !");
	say("Recompiling my combat code!");
	return (*this);
}

void
NinjaTrap::rangedAttack(std::string const &target)
{
	say() << "I'm a tornado of death and bullets! (" << target << " receive " << 
		this->_rangedAttackDamage << " ranged  damages !)(NinjaTrap)" << std::endl;
}

void
NinjaTrap::meleeAttack(std::string const &target)
{
	say() << "Take that! (" << target << " receive " << 
		this->_meleeAttackDamage << " melee damages !)(NinjaTrap)" << std::endl;
}

void
NinjaTrap::ninjaShoebox(ClapTrap &target)
{
	say() << "do somthing funny to a ClapTrap named " << target.getName() << " !" << std::endl;
}

void
NinjaTrap::ninjaShoebox(FragTrap &target)
{
	say() << "do somthing funny to a FragTrap named " << target.getName() << " !" << std::endl;
}

void
NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	say() << "do somthing funny to a ScavTrap named " << target.getName() << " !" << std::endl;
}

void
NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	say() << "do somthing funny to a NinjaTrap named " << target.getName() << " !" << std::endl;
}