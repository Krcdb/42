/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:30:21 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 16:39:23 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist():
	AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(const PlasmeRifle &other):
	AWeapon(other)
{
}

PowerFist::~PowerFist()
{
}

PowerFist&
PowerFist::operator=(const PowerFist &other)
{
	AWeapon::operator =(other);

	return (*this);
}

void
PowerFist::attack()
{
	std::cout << "* Et ca fait BIM BAM BOUM *" << std::endl;
}
