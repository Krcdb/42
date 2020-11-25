/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:11:13 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 18:17:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serial.hpp"

int		main()
{
	srand(time(NULL));
	void *raw = serialize();
	Data *data = deserialize(raw);

	std::cout << "s1 : " << data->s1 << std::endl;
	std::cout << "n  : " << data->n << std::endl;
	std::cout << "s2 : " << data->s2 << std::endl;
	return (0);
}