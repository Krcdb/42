/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:08:33 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 17:35:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <cctype>
# include <cmath>
# include <climits>
# include <cstring>
# include <iostream>
# include <iomanip>

class Scalar
{
	private:
		void	toChar(double value);
		void	toInt(double value);
		void	toFloat(double value, int pre);
		void	toDouble(double value, int pre);
		
	public:
		Scalar();
		Scalar(const Scalar &other);

		~Scalar();

		Scalar& operator=(const Scalar &other);

		void	startConvertion(double value, int pre);
};

#endif