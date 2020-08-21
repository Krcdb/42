/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:15:33 by memartin          #+#    #+#             */
/*   Updated: 2020/08/20 20:21:26 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include <iostream>

class Human
{
	private:
		void			meleeAttack(std::string const & target);
		void			rangedAttack(std::string const & target);
		void			intimidatingShout(std::string const & target);
		std::string		m_name;

	public:
		Human();
		Human(std::string name);
		virtual ~Human();
		void		action(std::string const & action_name, std::string const & target);
};

#endif
