/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:03:04 by memartin          #+#    #+#             */
/*   Updated: 2020/10/21 16:40:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) :
	_name("default"),
	_hp(100),
	_hpMax(100),
	_ep(100),
	_epMax(100),
	_level(1),
	_meleeAttackDamage(30),
	_rangedAttackDamage(20),
	_armorDamageReduction(5)
{
	say("created !");
	say("Hey everybody! Check out my package!");
}

FragTrap::FragTrap(std::string name):
	_name(name),
	_hp(100),
	_hpMax(100),
	_ep(100),
	_epMax(100),
	_level(1),
	_meleeAttackDamage(30),
	_rangedAttackDamage(20),
	_armorDamageReduction(5)
	
{
	say("created !");
	say("Hey everybody! Check out my package!");
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
	say("copied !");
	say("This time it'll be awesome, I promise!");
}


FragTrap::~FragTrap()
{
	say("Aww! Come on!");
	say("destroyed !");
}

FragTrap&
FragTrap::operator =(const FragTrap &other)
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
	say("Recompiling my combat code!");
	return (*this);
}

std::ostream&
FragTrap::say(void)
{
	return (std::cout << this->_name << " : ");
}

std::ostream&
FragTrap::say(std::string output)
{
	return (say() << output << std::endl);
}

void
FragTrap::rangedAttack(std::string const &target)
{
	say() << "I'm a tornado of death and bullets! (" << target << " receive " << 
		this->_rangedAttackDamage << " ranged  damages !)" << std::endl;
}

void
FragTrap::meleeAttack(std::string const &target)
{
	say() << "Take that! (" << target << " receive " << 
		this->_meleeAttackDamage << " melee damages !)" << std::endl;
}

void
FragTrap::takeDamage(unsigned int amount)
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
FragTrap::beRepaired(unsigned int amount)
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
FragTrap::vaultHunter_dot_exe(std::string const &target)
{
	if (this->_ep < 25)
	{
		say("Oy ! I need more EP !");
		return ;
	}
	static const std::string attacks[] = {
		"Blightbot",
		"Mechromagician",
		"Miniontrap",
		"Knock-knock jokes",
		"Shhhh...trap"
	};

	static const int damages[] = {
		32,
		46,
		15,
		0,
		2
	};

	int	random = rand() % 5;
	
	this->_ep -= 25;

	say() << "use " << attacks[random] << std::endl;
	say() << "Eat my random attack ! (" << target << " receive " << 
		damages[random] << " damages !)" << std::endl;
}

void
FragTrap::displayStatus(void)
{
	say() << "current HP : " << this->_hp << " | current EP : " << this->_ep << std::endl;
}
