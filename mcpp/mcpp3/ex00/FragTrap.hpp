/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:38:00 by memartin          #+#    #+#             */
/*   Updated: 2020/10/18 18:00:44 by user42           ###   ########.fr       */
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
		int				_hp = 100;
		int				_hpMax = 100;
		int				_ep = 100;
		int				_epMax = 100;
		int				_level = 1;
		int				_meleeAttackDamage = 30;
		int				_rangedAttackDamage = 20;
		int				_armorDamageReduction = 5;
	
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
