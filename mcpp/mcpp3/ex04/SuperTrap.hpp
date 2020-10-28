/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:50:18 by memartin          #+#    #+#             */
/*   Updated: 2020/10/28 11:51:22 by memartin         ###   ########.fr       */
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
};

#endif
