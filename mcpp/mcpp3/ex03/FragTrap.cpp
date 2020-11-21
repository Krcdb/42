/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:03:04 by memartin          #+#    #+#             */
/*   Updated: 2020/10/27 19:05:46 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void):
	ClapTrap()
{
	say("created !");
	say("Hey everybody! Check out my package!");
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5)
{
	say("created !");
	say("Hey everybody! Check out my package!");
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
	say("copied !");
	say("This time it'll be awesome, I promise!");
}


FragTrap::~FragTrap()
{
	say("Aww! Come on!");
	say("destroyed !");
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