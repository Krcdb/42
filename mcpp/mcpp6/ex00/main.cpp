/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:08:21 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 17:47:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int		getPrecision(char *str)
{
	unsigned int	before;
	unsigned int	after;

	before = 0;
	while (str[before] && str[before] != '.')
		before++;
	after = before + 1;
	while (str[after] && std::isdigit(str[after]))
		after++;
	after -= before;
	return ((strlen(str) == before || after == 1) ? 1 : after - 1);	
}

int		main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cout << "Enter at least an argument" << std::endl;
		return (0);
	}
	Scalar scalar;
	
	for (int i = 1; i < ac; i++)
	{
		scalar.startConvertion(atof(av[i]), getPrecision(av[i]));
		std::cout << std::endl;
	}
	return (0);
}