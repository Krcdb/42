/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:16:18 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 18:56:54 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion():
	Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &other):
	Enemy(other)
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "*SPROTCH*" << std::endl;
}

RadScorpion&
RadScorpion::operator=(const RadScorpion &other)
{
	Enemy::operator =(other);

	return (*this);
}

void
RadScorpion::takeDamage(int dmg)
{
	Enemy::takeDamage(dmg);
}
