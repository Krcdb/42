/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:27:46 by memartin          #+#    #+#             */
/*   Updated: 2020/11/19 19:00:02 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad: public ISquad
{
	private:
		int		_size;
		ISpaceMarine	**_squad;

	public:
		Squad();
		Squad(const Squad &other);

		virtual ~Squad();
		
		Squad& operator=(const Squad &other);

		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int nb) const;
		virtual int push(ISpaceMarine* marine);
};

#endif
