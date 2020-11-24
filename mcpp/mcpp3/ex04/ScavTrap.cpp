/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:03:04 by memartin          #+#    #+#             */
/*   Updated: 2020/11/24 15:42:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
	ClapTrap()
{
	say("created !");
	say("Let's get this party started!");
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3)
{
	say("created !");
	say("Let's get this party started!");
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
	say("copied !");
	say("This time it'll be awesome, I promise!");
}


ScavTrap::~ScavTrap()
{
	say("End of transmission");
	say("destroyed !");
}

ScavTrap&
ScavTrap::operator =(const ScavTrap &other)
{
	ClapTrap::operator =(other);

	say("assigned !");
	say("This time it'll be awesome, I promise!");
	return (*this);
}

void
ScavTrap::rangedAttack(std::string const &target)
{
	say() << "I'm a tornado of death and bullets! (" << target << " receive " << 
		this->_rangedAttackDamage << " ranged  damages !)(ScavTrap)" << std::endl;
}

void
ScavTrap::meleeAttack(std::string const &target)
{
	say() << "Take that! (" << target << " receive " << 
		this->_meleeAttackDamage << " melee damages !)(ScavTrap)" << std::endl;
}

void
ScavTrap::challengeNewcomer(std::string const &target)
{
	if (this->getEp() < 25)
	{
		say("Gime EP !");
		return ;
	}
	static const std::string attacks[] = {
		" to kill 5 Scag !",
		" to bring him back a shootgun !",
		" to come at i birthday party !",
		" to escort him to Jack !"
	};

	int	random = rand() % 4;
	
	this->getEp() -= 25;

	say() << this->getName() << " challenge " << target << attacks[random] << std::endl; 
}
