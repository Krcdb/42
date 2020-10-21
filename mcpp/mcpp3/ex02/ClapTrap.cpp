/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:55:03 by memartin          #+#    #+#             */
/*   Updated: 2020/10/21 18:26:55 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_name("default"),
	_hp(1),
	_hpMax(1),
	_ep(1),
	_epMax(1),
	_level(1),
	_meleeAttackDamage(3),
	_rangedAttackDamage(2),
	_armorDamageReduction(5)
{
	say("base ClapTrap created !");

}
ClapTrap::ClapTrap(std::string name, int hp, int hpMax, int ep, int epMax, int level, int meleeAttackDamage, int rangedAttackDamage, int armorDamageReduction):
	_name(name),
	_hp(hp),
	_hpMax(hpMax),
	_ep(ep),
	_epMax(epMax),
	_level(level),
	_meleeAttackDamage(meleeAttackDamage),
	_rangedAttackDamage(rangedAttackDamage),
	_armorDamageReduction(armorDamageReduction)
	
{
	say("base ClapTrap created !");
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	say("copied (claptrap)!");
}


ClapTrap::~ClapTrap(void)
{
	say("ClapTrap destroy !");
	say("destroyed !");
}

ClapTrap&
ClapTrap::operator =(const ClapTrap &other)
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
	say("assigned (claptrap)!");
	return (*this);
}

std::ostream&
ClapTrap::say(void)
{
	return (std::cout << this->_name << " : ");
}

std::ostream&
ClapTrap::say(std::string output)
{
	return (say() << output << std::endl);
}

void
ClapTrap::rangedAttack(std::string const &target)
{
	say() << "I'm a tornado of death and bullets! (" << target << " receive " << 
		this->_rangedAttackDamage << " ranged  damages !)" << std::endl;
}

void
ClapTrap::meleeAttack(std::string const &target)
{
	say() << "Take that! (" << target << " receive " << 
		this->_meleeAttackDamage << " melee damages !)" << std::endl;
}

void
ClapTrap::takeDamage(unsigned int amount)
{
	int	damage;
	damage = amount - this->_armorDamageReduction;
	
	if (damage <= 0 && this->_hp != 0)
		say("Nice try !") << this->_name << " received 0 damages !" << std::endl;
	else if (damage >= this->_hp)
	{
		say("Woah! Oh! Jeez!") << this->_name << " is dead ! See you space FR4G-TP" << std::endl;
		this->_hp = 0;
	}
	else
	{
		say("Ouch !") << this->_name << " received " << damage << " damages !" << std::endl;
		this->_hp -= damage;
	}
}

void
ClapTrap::beRepaired(unsigned int amount)
{
	int heal;

	if (amount > (this->_hpMax - this->_hp))
		heal = this->_hpMax - this->_hp;
	else
		heal = amount;
	if (this->_hp == 100)
		say("I'm full bro !");
	else
	{
		say("Yay ! Healing !") << this->_name << " healed for " << heal << " hp !" << std::endl;
		this->_hp += heal;
	}
}

void
ClapTrap::displayStatus(void)
{
	say() << "current HP : " << this->_hp << " | current EP : " << this->_ep << std::endl;
}
