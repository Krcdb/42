/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:58:56 by memartin          #+#    #+#             */
/*   Updated: 2020/11/27 12:48:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon():
	_apcost(0),
	_dmg(0),
	_name("")
{
}

AWeapon::AWeapon(std::string const & name, int apcost, int dmg):
	_apcost(apcost),
	_dmg(dmg),
	_name(name)
{
}

AWeapon::AWeapon(const AWeapon &other):
	_apcost(other._apcost),
	_dmg(other._dmg),
	_name(other._name)
{
}

AWeapon::~AWeapon()
{
}

AWeapon&
AWeapon::operator=(const AWeapon &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_apcost = other._apcost;
		this->_dmg = other._dmg;
	}
	return (*this);
}

const std::string&
AWeapon::getName() const
{
	return (this->_name);
}

int
AWeapon::getAPCost() const
{
	return (this->_apcost);
}

int
AWeapon::getDamage() const
{
	return (this->_dmg);
}
