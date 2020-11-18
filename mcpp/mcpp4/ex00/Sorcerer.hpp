/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:43:05 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 14:34:04 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
	private:
		std::string		_name;
		std::string		_title;
		Sorcerer(void);

	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(const Sorcerer &other);
		~Sorcerer(void);

		Sorcerer& operator=(const Sorcerer &other);

		void	polymorph(Victim const &) const;

		const std::string&		getName(void) const;
		const std::string&		getTitle(void) const;
};

std::ostream &operator <<(std::ostream &stream, Sorcerer &sorcerer);

#endif
