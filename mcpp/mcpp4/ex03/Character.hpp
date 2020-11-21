/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:18:13 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 10:28:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define MAX_INVENTORY 4

class Character: public ICharacter
{
    private:
    	std::string 	_name;
    	AMateria 		*_inventory[MAX_INVENTORY];

		Character();
		void initInventory();

	public:
		Character(std::string name);
		Character(const Character &other);
		
		virtual ~Character();

		Character& operator=(const Character &other);

		virtual void equip(AMateria *materia);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
		virtual const std::string & getName() const;
};

#endif