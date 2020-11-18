/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:17:15 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 14:36:53 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
	protected:
		std::string		_name;
		Victim(void);

	public:
		Victim(std::string name);
		Victim(const Victim &other);
		virtual ~Victim(void);

		Victim& operator=(const Victim &other);

		virtual void	getPolymorphed(void) const;

		const std::string&		getName(void) const;
};

std::ostream &operator <<(std::ostream &stream, Victim &victim);

#endif
