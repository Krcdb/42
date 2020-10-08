/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:14:18 by memartin          #+#    #+#             */
/*   Updated: 2020/10/08 17:40:22 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:		
		int					_value;
		static const int	_bitCount;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		
		
		~Fixed();
		
		Fixed &operator=(const Fixed &other);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);

		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream &operator <<(std::ostream &stream, const Fixed &fixed);

#endif		
