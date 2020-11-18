/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:45:16 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 16:59:31 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
{
}

Enemy::Enemy(int hp, std:string const & type):
	_hp(hp),
	_type(type)
{
}

Enemy::Enemy(const Enemy &other):
	_hp(other._hp),
	_type(other._type)
{
}

Enemy::~Enemy()
{
}

Enemy&
Enemy::operator=(const Enemy &other)
{
	if (this != &other)
	{
		this->_hp = other._hp;
		this->_type = other._type;
	}
	return (*this);
}

const std::string&
Enemy::getType() const
{
	return (this->_type);
}

int
Enemy::getHP() const
{
	return (this->_hp);
}

void
Enemy::takeDamage(int dmg)
{
	if (dmg < 0)
		return ;
	this->_hp -= dmg;

	if (this->_hp < 0)
		this->_hp = 0;
}
