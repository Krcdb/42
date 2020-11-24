/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:50:18 by memartin          #+#    #+#             */
/*   Updated: 2020/11/24 15:52:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{	
	public:
		SuperTrap(void);
		SuperTrap(std::string name);
		SuperTrap(const SuperTrap &other);
		virtual ~SuperTrap(void);

		SuperTrap &operator =(const SuperTrap &other);
		void				rangedAttack(std::string const &target);
		void				meleeAttack(std::string const &target);
};

#endif
