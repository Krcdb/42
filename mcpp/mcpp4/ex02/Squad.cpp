/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:23:00 by memartin          #+#    #+#             */
/*   Updated: 2020/11/19 19:02:38 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad():
    _size(0),
    _squad(NULL)
{

}

Squad::Squad(const Squad &other):
    _size(0),
    _squad(NULL)
{
    this->operator=(other);
}

Squad::~Squad()
{
    if (this->_squad)
    {
        for (int i = 0; i < this->_size; i++)
        {
            delete this->_squad[i];
            this->_squad[i] = NULL;
        }
        delete[] this->_squad;
        this->_squad = NULL;
    }
}

Squad&
Squad::operator=(const Squad &other)
{
    if (this != &other)
    {
        for (int i = 0; i < this->_size; i++)
        {
            delete this->_squad[i];
            this->_squad[i] = NULL;
        }
        this->_squad = new ISpaceMarine*[other._size];
        this->_size = other._size;
        for (int i = 0; i < this->_size; i++)
            this->_squad[i] = other._squad[i]->clone();
    }
    return (*this);
}

int
Squad::getCount() const
{
    return (this->_size);
}

ISpaceMarine* 
Squad::getUnit(int nb) const
{
    if (nb < 0 || nb >= this->_size)
        return (NULL);
    return (this->_squad[nb]);
}

int
Squad::push(ISpaceMarine* marine)
{
    for (int i = 0; i < this->_size; i++)
    {
        if (!marine || marine == this->_squad[i])
            return (this->_size);
    }
    ISpaceMarine **newsquad = new ISpaceMarine*[this->_size + 1];
    for (int i = 0; i < this->_size; i++)
        newsquad[i] = this->_squad[i];
    newsquad[this->_size] = marine;
    delete[] this->_squad;
    this->_squad = newsquad;
    this->_size++;
    return (this->_size);
}
