/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:40:49 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 10:45:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character():
	_name("")
{
	this->initInventory();
}

Character::Character(std::string name):
	_name(name)
{
	this->initInventory();
}

Character::Character(const Character &other):
	_name(other._name)
{
	this->initInventory();
	this->operator=(other);
}

Character::~Character()
{
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}

Character&
Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < MAX_INVENTORY; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

void
Character::initInventory()
{
	for (int i = 0; i < MAX_INVENTORY; i++)
		this->_inventory[i] = NULL;
}

void
Character::equip(AMateria *materia)
{
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = materia;
			break;
		}
	}
}

void
Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_INVENTORY)
		return ;
	this->_inventory[idx] = NULL;
}

void
Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= MAX_INVENTORY)
		return ;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}

const std::string&
Character::getName() const
{
	return (this->_name);
}