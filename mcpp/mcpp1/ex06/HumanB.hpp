#ifndef _HUMANB_HPP_
# define _HUMANB_HPP_

# include <string>
# include <iostream>
# include "Weapon.hpp"

class		HumanB
{
	private:
		std::string		m_name;
		Weapon			*m_weapon;

	public:
		HumanB(std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon &weapon);
};

#endif
