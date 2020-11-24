/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:38:00 by memartin          #+#    #+#             */
/*   Updated: 2020/11/24 15:42:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{	
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		virtual ~FragTrap(void);

		FragTrap &operator =(const FragTrap &other);
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			vaultHunter_dot_exe(std::string const &target);
};

#endif
