/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:58:56 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 16:55:53 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
{
}

AWeapon::AWeapon(std::string const & name, int apcost, int dmg):
	_name(name),
	_apcost(apcost),
	_dmg(dmg)
{
}

AWeapon::AWeapon(const AWeapon &other)
	_name(other._name),
	_apcost(other._apcost),
	_dmg(other._dmg)
{
}

AWeapon::~AWeapon()
{
}

AWeapon
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

const std::string
AWaepon::getName() const
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
