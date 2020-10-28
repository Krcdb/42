/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:25:50 by memartin          #+#    #+#             */
/*   Updated: 2020/10/28 11:58:44 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void):
	ClapTrap()
{
	say("NinjaBoy created !");
}

NinjaTrap::NinjaTrap(std::string name):
	ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5)
{
	say("NinjaBoy created !");
}

NinjaTrap::NinjaTrap(const NinjaTrap &other)
{
	*this = other;
	say("copied !");
	say("This time it'll be awesome, I promise!");
}


NinjaTrap::~NinjaTrap()
{
	say("NinjaBoy destroyed !");
}

NinjaTrap&
NinjaTrap::operator =(const NinjaTrap &other)
{
	ClapTrap::operator =(other);

	say("assigned !");
	say("Recompiling my combat code!");
	return (*this);
}

void
NinjaTrap::ninjaShoebox(ClapTrap &target)
{
	say() << "attack a ClapTrap named " << target.getName() << " !" << std::endl;
}

void
NinjaTrap::ninjaShoebox(FragTrap &target)
{
	say() << "attack a FragTrap named " << target.getName() << " !" << std::endl;
}

void
NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	say() << "attack a ScavTrap named " << target.getName() << " !" << std::endl;
}

void
NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	say() << "attack a NinjaTrap named " << target.getName() << " !" << std::endl;
}
