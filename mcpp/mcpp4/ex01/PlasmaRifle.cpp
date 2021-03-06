/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:30:21 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 19:17:09 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle():
	AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &other):
	AWeapon(other)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle&
PlasmaRifle::operator=(const PlasmaRifle &other)
{
	AWeapon::operator =(other);

	return (*this);
}

void
PlasmaRifle::attack() const
{
	std::cout << "* pew pew pew *" << std::endl;
}

