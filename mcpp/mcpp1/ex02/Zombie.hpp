#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string		m_name;
		std::string		m_type;
	
	public:
		Zombie();
		Zombie(std::string name, std::string type);
		virtual ~Zombie();
		
		void	announce();
};

#endif
