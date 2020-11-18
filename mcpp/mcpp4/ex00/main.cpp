/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:21:11 by memartin          #+#    #+#             */
/*   Updated: 2020/11/18 14:39:52 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"

int		main()
{
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << "\n Copy and assignement\n\n";
	jim.getPolymorphed();
	joe.getPolymorphed();
	Victim *jimByCopy = new Victim(jim);
	Peon *joeByCopy = new Peon(joe);
	delete jimByCopy;
	delete joeByCopy;
	return (0);
}
