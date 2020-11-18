/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:40:44 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 16:54:34 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
	private:
		int				_hp;
		std::string		_type;
		Enemy();

	public:
		Enemy(int hp, std::string const & type);
		Enemy(const Enemy &other);
		virtual ~Enemy(void);

		Enemy& operator=(const Enemy &other);
		
		const std::string&	getType(void) const;
		int		getHP(void) const;

		virtual void	takeDamage(int dmg);
};

#endif
