/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:14:02 by memartin          #+#    #+#             */
/*   Updated: 2020/10/08 17:44:25 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int
Fixed::_bitCount = 8;

Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::~Fixed(void)
{
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	this->_value = value << _bitCount;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << _bitCount));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &
Fixed::operator =(const Fixed &other)
{
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}

	return (*this);
}

int
Fixed::getRawBits(void) const
{
	return (this->_value);
}

void
Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int
Fixed::toInt(void) const
{
	return (this->_value >> _bitCount);
}

float
Fixed::toFloat(void) const
{
	return (((float)this->_value) / (1 << _bitCount));
}

std::ostream&
operator <<(std::ostream &stream, const Fixed &fixed)
{
	return (stream << fixed.toFloat());
}
