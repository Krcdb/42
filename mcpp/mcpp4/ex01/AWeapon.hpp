/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:48:53 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 16:55:21 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class Aweapon
{
	private:
		int				_apcost;
		int				_dmg;
		std::string		_name;
		AWeapon(void);

	public:
		AWeapon(std::string const & name, int, apcost, int dmg);
		AWeapon(const AWeapon &other);

		AWeapon& operator=(const AWeapon &other);

		virtual ~AWeapon(void);
		
		const std::string&	getName(void) const;
		int		getAPCost(void) const;
		int		getDamage(void) const;
		
		virtual void	attack(void) const = 0;
};

#endif	
