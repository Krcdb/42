/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:47:55 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 14:37:45 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon: public Victim
{
	private:
		Peon(void);

	public:
		Peon(std::string name);
		Peon(const Peon &other);
		virtual ~Peon(void);

		Peon& operator=(const Peon &other);

		virtual void	getPolymorphed(void) const;
};

std::ostream &operator <<(std::ostream &stream, Peon &peon);

#endif
