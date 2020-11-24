/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:26:12 by memartin          #+#    #+#             */
/*   Updated: 2020/11/24 15:32:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{	
	public:
		NinjaTrap(void);
		NinjaTrap(std::string name);
		NinjaTrap(const NinjaTrap &other);
		virtual ~NinjaTrap(void);

		NinjaTrap &operator =(const NinjaTrap &other);

		void	rangedAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		void	ninjaShoebox(ClapTrap &target);
		void	ninjaShoebox(FragTrap &target);
		void	ninjaShoebox(ScavTrap &target);
		void	ninjaShoebox(NinjaTrap &target);
};

#endif
