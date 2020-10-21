/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:26:33 by user42            #+#    #+#             */
/*   Updated: 2020/10/21 16:41:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	ft("Michel");
	ft.displayStatus();
	
	std::cout << std::endl;

	ft.beRepaired(100);
	ft.displayStatus();

	std::cout << std::endl;
	
	ft.rangedAttack("Bob");
	ft.meleeAttack("Bob");

	std::cout << std::endl;

	ft.takeDamage(0);
	ft.displayStatus();
	ft.takeDamage(20);
	ft.displayStatus();
	ft.takeDamage(200);
	ft.displayStatus();
	ft.beRepaired(200);
	ft.displayStatus();
	
	std::cout << std::endl;
	
	for (int i = 0; i < 7; i++)
	{
		ft.vaultHunter_dot_exe("FRAG");
		ft.displayStatus();
	}


	return (0);
}
