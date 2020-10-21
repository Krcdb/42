/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:25:35 by memartin          #+#    #+#             */
/*   Updated: 2020/10/21 17:28:34 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	ScavTrap	st("My BB");
	st.displayStatus();
	
	std::cout << std::endl;

	st.beRepaired(100);
	st.displayStatus();

	std::cout << std::endl;
	
	st.rangedAttack("Bob");
	st.meleeAttack("Bob");

	std::cout << std::endl;

	st.takeDamage(0);
	st.displayStatus();
	st.takeDamage(20);
	st.displayStatus();
	st.takeDamage(200);
	st.displayStatus();
	st.beRepaired(200);
	st.displayStatus();
	
	std::cout << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		st.challengeNewcomer("FR4G");
		st.displayStatus();
	}


	return (0);
}
