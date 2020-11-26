/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:06:54 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 16:34:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int	main(void)
{
	int		nb_array[] = {1, 2, 3, 4, 5, 6};
	char	str[] = "abcdef";

	iter(nb_array, 6, &display);
	std::cout << std::endl;

	iter(str, 6, &display);
	std::cout << std::endl;
}