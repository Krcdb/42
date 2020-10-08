/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:14:18 by memartin          #+#    #+#             */
/*   Updated: 2020/10/08 17:15:21 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:		
		int					_value;
		static const int	_bitCount;

	public:
		Fixed();
		~Fixed();
		
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
};

#endif		
