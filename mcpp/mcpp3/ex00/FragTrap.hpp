/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:38:00 by memartin          #+#    #+#             */
/*   Updated: 2020/09/29 17:56:57 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>

class FragTrap
{
	private:
		std::string		_name;
		unsigned int	_hp = 100;
		unsigned int	_hpMax = 100;
		unsigned int	_ep = 100;
		unsigned int	_epMax = 100;
		unsigned int	_level = 1;
		unsigned int	_meleeAttackDamage = 30;
		unsigned int	_rangedAttackDamage = 20;
		unsigned int	_armorDamageReduction = 5;
	
	public:
		FragTrap();
		FragTrap(std::string name);
		virtual ~FragTrap();
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			vaultHunter_dot_exe(std::string const &target);
};

#endif
