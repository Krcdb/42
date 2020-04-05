#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

# include <random>
# include <chrono>
# include <string>
# include <iostream>

class	Zombie
{
	private:
		std::string		m_name;

	public:
		Zombie();
		virtual ~Zombie();

		std::string		randomName(std::string::size_type length);
		void			setName();
		void			announce();
};

#endif
