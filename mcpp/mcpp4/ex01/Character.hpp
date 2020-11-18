/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:32:10 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 19:02:10 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

# include "Enemy.hpp"
# include "AWeapon.hpp"

class Character
{
	private:
		std::string	_name;
		int			_ap;
		AWeapon		*_weapon;
		Character(void);

	public:
		Character(std::string const &name);
		Character(const Character &other);
		virtual ~Character();

		Character& operator=(const Character &other);

		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);

		const std::string& getName() const;
		int getAP() const;
		AWeapon* getWeapon() const;
};

std::ostream& operator <<(std::ostream &stream, Character &character);

#endif
