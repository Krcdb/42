/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:28:40 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 10:56:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->initInventory();
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	this->initInventory();
	this->operator=(other);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}

MateriaSource&
MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
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
MateriaSource::initInventory()
{
	for (int i = 0; i < MAX_INVENTORY; i++)
		this->_inventory[i] = NULL;
}

void
MateriaSource::learnMateria(AMateria *materia)
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

AMateria*
MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	return (NULL);
}