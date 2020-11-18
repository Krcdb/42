/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:25:02 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 16:40:06 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist: public AWeapon
{
	public:
		PowerFist();
		PowerFist(const PowerFist &other);
		virtual ~PowerFist();

		PowerFist&	operator=(const PowerFist &other);

		virtual void	attack() const;
};

#endif
