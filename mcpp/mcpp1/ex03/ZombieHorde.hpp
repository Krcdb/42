#ifndef _ZOMBIEHORDE_HPP_
# define _ZOMBIEHORDE_HPP_

# include <random>
# include <chrono>
# include <iostream>
# include <string>
# include "Zombie.hpp"

class	ZombieHorde
{
	private:
		Zombie *horde;
		int		m_nb;
	
	public:
		ZombieHorde();
		ZombieHorde(int nb);
		virtual ~ZombieHorde();

		void			announce();
};

#endif
