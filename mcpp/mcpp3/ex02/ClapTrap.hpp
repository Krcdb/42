/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:38:00 by memartin          #+#    #+#             */
/*   Updated: 2020/11/24 15:24:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class ClapTrap
{
	private:
		std::string		_name;
		int				_hp;
		int				_hpMax;
		int				_ep;
		int				_epMax;
		int				_level;
		int				_armorDamageReduction;
	
	protected:
		int				_meleeAttackDamage;
		int				_rangedAttackDamage;
		std::ostream&	say(void);
		std::ostream&	say(std::string output);

	public:
		ClapTrap(void);
		ClapTrap(std::string name, int hp, int hpMax, int ep, int epMax, int level, int meleeAttackDamage, int rangedAttackDamage, int armorDamageReduction);
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap(void);

		ClapTrap &operator =(const ClapTrap &other);

		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		void				displayStatus(void);
		int					&getHp(void);
		int					&getEp(void);
		const std::string	&getName(void);
};

#endif
