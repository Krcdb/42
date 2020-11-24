/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:04:41 by memartin          #+#    #+#             */
/*   Updated: 2020/11/24 15:32:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{	
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		virtual ~ScavTrap(void);

		ScavTrap &operator =(const ScavTrap &other);

		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			challengeNewcomer(std::string const &target);
};

#endif
