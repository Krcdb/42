#ifndef _ZOMBIEEVENT_HPP_
# define _ZOMBIEEVENT_HPP_

# include <iostream>
# include <string>
# include <random>
# include <chrono>
# include "Zombie.hpp"

class	ZombieEvent
{
	private:
		std::string		m_type;

	public:
		ZombieEvent();
		virtual ~ZombieEvent();

		void			setZombieType(std::string type);
		std::string		randomName(std::string::size_type length);
		Zombie			*newZombie();
		Zombie			*randomChump();
};

#endif
