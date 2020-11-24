/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:03:04 by memartin          #+#    #+#             */
/*   Updated: 2020/11/24 15:41:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void):
	ClapTrap()
{
	say("FragBoy created !");
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5)
{
	say("FragBoy created !");
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
	say("copied !");
	say("This time it'll be awesome, I promise!");
}


FragTrap::~FragTrap()
{
	say("FragBoy destroyed !");
}

FragTrap&
FragTrap::operator =(const FragTrap &other)
{
	ClapTrap::operator =(other);

	say("assigned !");
	say("Recompiling my combat code!");
	return (*this);
}

void
FragTrap::rangedAttack(std::string const &target)
{
	say() << "I'm a tornado of death and bullets! (" << target << " receive " << 
		this->_rangedAttackDamage << " ranged  damages !)(FragTrap)" << std::endl;
}

void
FragTrap::meleeAttack(std::string const &target)
{
	say() << "Take that! (" << target << " receive " << 
		this->_meleeAttackDamage << " melee damages !)(FragTrap)" << std::endl;
}

void
FragTrap::vaultHunter_dot_exe(std::string const &target)
{
	if (this->getEp() < 25)
	{
		say("Oy ! I need more EP !");
		return ;
	}
	static const std::string attacks[] = {
		"Blightbot",
		"Mechromagician",
		"Miniontrap",
		"Knock-knock jokes",
		"Shhhh...trap"
	};

	static const int damages[] = {
		32,
		46,
		15,
		0,
		2
	};

	int	random = rand() % 5;
	
	this->getEp() -= 25;

	say() << "use " << attacks[random] << std::endl;
	say() << "Eat my random attack ! (" << target << " receive " << 
		damages[random] << " damages !)" << std::endl;
}
