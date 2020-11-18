/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:27:02 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 19:09:36 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
}

Character::Character(std::string const &name):
	_name(name),
	_ap(40),
	_weapon(NULL)
{
}

Character::Character(const Character &other):
	_name(other._name),
	_ap(other._ap),
	_weapon(other._weapon)
{
}

Character::~Character()
{
}

Character&
Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_ap = other._ap;
		this->_weapon = other._weapon;
	}
	return (*this);
}

void
Character::recoverAP()
{
	this->_ap += 10;
	if (this->_ap > 40)
		this->_ap = 40;
}

void
Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void
Character::attack(Enemy *enemy)
{
	if (!this->_weapon || !enemy)
		return ;
	if (this->_ap - this->_weapon->getAPCost() < 0)
	{
		std::cout << "Not enough AP !" << std::endl;
		return ;
	}
	this->_ap -= this->_weapon->getAPCost();
	std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
	this->_weapon->attack();
	enemy->takeDamage(this->_weapon->getDamage());
	if (enemy->getHP() <= 0)
		delete enemy;
}

const std::string&
Character::getName() const
{
	return (this->_name);
}

int
Character::getAP() const
{
	return (this->_ap);
}

AWeapon*
Character::getWeapon() const
{
	return (this->_weapon);
}

std::ostream&
operator <<(std::ostream &stream, Character &character)
{
	if (character.getWeapon())
		stream << character.getName() << " has " << character.getAP() << " AP and wields a " << character.getWeapon()->getName() << std::endl;
	else
		stream << character.getName() << " has " << character.getAP() << " AP and is unarmed"  << std::endl;

	return (stream);
}
