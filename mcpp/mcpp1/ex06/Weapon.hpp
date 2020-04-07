#ifndef _WEAPON_HPP_
# define _WEAPON_HPP_

# include <string>
# include <iostream>

class		Weapon
{
	private:
		std::string m_type;

	public:
		Weapon();
		Weapon(std::string type);
		virtual ~Weapon();

		std::string		getType();
		void			setType(std::string new_type);
};

#endif
