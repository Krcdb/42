/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:03:04 by memartin          #+#    #+#             */
/*   Updated: 2020/11/24 15:20:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
	_name("default"),
	_hp(100),
	_hpMax(100),
	_ep(50),
	_epMax(50),
	_level(1),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReduction(3)
{
	say("created !");
	say("Let's get this party started!");
}

ScavTrap::ScavTrap(std::string name):
	_name(name),
	_hp(100),
	_hpMax(100),
	_ep(50),
	_epMax(50),
	_level(1),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReduction(3)
	
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

std::ostream&
ScavTrap::say(void)
{
	return (std::cout << this->_name << " : ");
}

std::ostream&
ScavTrap::say(std::string output)
{
	return (say() << output << std::endl);
}

void
ScavTrap::rangedAttack(std::string const &target)
{
	say() << "Try this ! (" << target << " receive " << 
		this->_rangedAttackDamage << " ranged  damages !)" << std::endl;
}

void
ScavTrap::meleeAttack(std::string const &target)
{
	say() << "Aya ! (" << target << " receive " << 
		this->_meleeAttackDamage << " melee damages !)" << std::endl;
}

void
ScavTrap::takeDamage(unsigned int amount)
{
	int	damage;
	damage = amount - this->_armorDamageReduction;
	
	if (damage <= 0 && this->_hp != 0)
		say("Try again !") << this->_name << " received 0 damages !" << std::endl;
	else if (damage >= this->_hp)
	{
		say("AArrgggh!") << this->_name << " is dead ! See you space Scav" << std::endl;
		this->_hp = 0;
	}
	else
	{
		say("Aw !") << this->_name << " received " << damage << " damages !" << std::endl;
		this->_hp -= damage;
	}
}

void
ScavTrap::beRepaired(unsigned int amount)
{
	int heal;

	if (amount > (unsigned int)(this->_hpMax - this->_hp))
		heal = this->_hpMax - this->_hp;
	else
		heal = amount;
	if (this->_hp == 100)
		say("I don't need it thanks !");
	else
	{
		say("Yay ! Healing !") << this->_name << " healed for " << heal << " hp !" << std::endl;
		this->_hp += heal;
	}
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

void
ScavTrap::displayStatus(void)
{
	say() << "current HP : " << this->_hp << " | current EP : " << this->_ep << std::endl;
}
