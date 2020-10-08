/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:14:02 by memartin          #+#    #+#             */
/*   Updated: 2020/10/08 17:14:05 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int
Fixed::_bitCount = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->_value = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

	this->_value = 0;
}


Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
}

Fixed &
Fixed::operator =(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &other)
	{
		this->_value = other.getRawBits();
	}

	return (*this);
}

int
Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->_value);
}

void
Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_value = raw;
}
