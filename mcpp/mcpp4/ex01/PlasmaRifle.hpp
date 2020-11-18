/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:25:02 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 16:30:02 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
	public:
		PlasmaRifle();
		PlasmaRifle(const PlasmaRifle &other);
		virtual ~PlasmaRifle();

		PlasmaRifle&	operator=(const PlasmaRifle &other);

		virtual void	attack() const;
};

#endif
