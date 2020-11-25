/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serial.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:54:23 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 18:24:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIAL_HPP
# define SERIAL_HPP

# include <string>
# include <iostream>

struct Data
{
	std::string s1;
	int	n;
	std::string s2;
};

void *serialize(void);
Data *deserialize(void * raw);

#endif