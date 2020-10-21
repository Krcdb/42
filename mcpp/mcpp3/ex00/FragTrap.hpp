/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:38:00 by memartin          #+#    #+#             */
/*   Updated: 2020/10/21 17:11:23 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class FragTrap
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
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		virtual ~FragTrap(void);

		FragTrap &operator =(const FragTrap &other);

		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			vaultHunter_dot_exe(std::string const &target);

		void			displayStatus(void);
};

#endif
