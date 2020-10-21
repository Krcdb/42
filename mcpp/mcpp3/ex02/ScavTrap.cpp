/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:03:04 by memartin          #+#    #+#             */
/*   Updated: 2020/10/21 18:18:26 by memartin         ###   ########.fr       */
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
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_hpMax = other._hpMax;
		this->_ep = other._ep;
		this->_epMax = other._epMax;
		this->_level = other._level;
		this->_meleeAttackDamage = other._meleeAttackDamage;
		this->_rangedAttackDamage = other._rangedAttackDamage;
		this->_armorDamageReduction = other._armorDamageReduction;
	}
	say("assigned !");
	say("This time it'll be awesome, I promise!");
	return (*this);
}

void
ScavTrap::challengeNewcomer(std::string const &target)
{
	if (this->_ep < 25)
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
	
	this->_ep -= 25;

	say() << this->_name << " challenge " << target << attacks[random] << std::endl; 
}
