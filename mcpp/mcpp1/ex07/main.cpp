/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:32:48 by memartin          #+#    #+#             */
/*   Updated: 2020/08/20 13:12:38 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int			main(int ac, char **av)
{
	if (ac != 4)
		std::cout << "Usage : ./Replace [FilePath] [s1] [s2]\n";

	Replace		rep(av[1], av[2], av[3]);
	if (rep.checkArgsAndRead())
		return (0);
	return (0);
}
