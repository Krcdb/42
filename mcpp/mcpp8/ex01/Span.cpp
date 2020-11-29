/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:20:32 by user42            #+#    #+#             */
/*   Updated: 2020/11/29 15:54:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n):
	_n(n)
{}

Span::Span(const Span &other)
{
	this->operator=(other);
}

Span::~Span()
{}

Span&
Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_n = other._n;
		this->_vector = other._vector;
	}
	return (*this);
}

void
Span::addNumber(int nb)
{
	if (this->_vector.size() >= this->_n)
		throw Span::CapacityReach();
	this->_vector.push_back(nb);
}

void
Span::addNumber(int from, int to)
{
	if (from >= to)
		throw Span::BadArgument();
	if (this->_vector.size() + (to - from + 1) > this->_n)
		throw Span::CapacityReach();
	for (int i = from; i <= to; i++)
		this->_vector.push_back(i);
}

void
Span::addNumberRand(int from, int to, int nb)
{
	if (from >= to)
		throw Span::BadArgument();
	if (this->_vector.size() + nb > this->_n)
		throw Span::CapacityReach();
	for (int i = 0; i < nb; i++)
		this->_vector.push_back(from + (rand() % (to - from)));
}

int
Span::shortestSpan()
{
	if (this->_vector.size() <= 1)
		throw Span::NeedAtLeastTwo();
	
	std::vector<int> tmp = std::vector<int>(this->_vector);
	std::sort(tmp.begin(), tmp.end());

	int shortest = -1;
	int diff;

	for (unsigned int i = 0; i < tmp.size() - 1; i++)
	{
		diff = std::abs(tmp[i] - tmp[i + 1]);
		if (shortest == -1 || diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

int
Span::longestSpan()
{
	if (this->_vector.size() <= 1)
		throw Span::NeedAtLeastTwo();
	return (*std::max_element(this->_vector.begin(), this->_vector.end()) - 
			*std::min_element(this->_vector.begin(), this->_vector.end()));
}

void
Span::display()
{
	for (unsigned long i = 0; i < this->_vector.size(); i++)
		std::cout << this->_vector[i] << " " << std::endl;
	std::cout << std::endl;
}

const char* Span::CapacityReach::what() const throw()
{
	return ("Span Exception : Capacity Reach");
}

const char* Span::BadArgument::what() const throw()
{
	return ("Span Exception : Bad Argument For >= To");
}

const char* Span::NeedAtLeastTwo::what() const throw()
{
	return ("Span Exception : Need a lest two elements");
}