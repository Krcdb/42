/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:04:41 by memartin          #+#    #+#             */
/*   Updated: 2020/10/21 17:27:30 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class ScavTrap
{
	private:
		std::string		_name;
		int				_hp;
		int				_hpMax;
		int				_ep;
		int				_epMax;
		int				_level;
		int				_meleeAttackDamage;
		int				_rangedAttackDamage;
		int				_armorDamageReduction;
	
	protected:
		std::ostream&	say(void);
		std::ostream&	say(std::string output);

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		virtual ~ScavTrap(void);

		ScavTrap &operator =(const ScavTrap &other);

		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			challengeNewcomer(std::string const &target);

		void			displayStatus(void);
};

#endif
