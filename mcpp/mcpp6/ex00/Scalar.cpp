/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:08:44 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 17:38:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar()
{
}

Scalar::Scalar(const Scalar &other)
{
	this->operator=(other);
}

Scalar::~Scalar()
{
}

Scalar&
Scalar::operator=(const Scalar &other)
{
	static_cast<void>(other);
	return (*this);
}

void
Scalar::startConvertion(double value, int pre)
{
	this->toChar(value);
	this->toInt(value);
	this->toFloat(value, pre);
	this->toDouble(value, pre);
}

void
Scalar::toChar(double value)
{
	char c;

	std::cout << "char convertion : ";
	if (std::isnan(value))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	c = static_cast<char>(value);
	if (!std::isprint(c))
		std::cout << "impossible" << std::endl;
	else
		std::cout << c << std::endl;
}

void
Scalar::toInt(double value)
{
	std::cout << "int convertion : ";
	if (std::isnan(value) || std::isinf(value)
		|| value > static_cast<double>(INT_MAX)
		|| value < static_cast<double>(INT_MIN))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void
Scalar::toFloat(double value, int pre)
{
	std::cout << "float convertion : " << std::setprecision(pre)
    	<< std::fixed << static_cast<float>(value) << "f" << std::endl;
}

void
Scalar::toDouble(double value, int pre)
{
	std::cout << "double convertion : " << std::setprecision(pre)
    	<< std::fixed << static_cast<double>(value) << std::endl;
}
