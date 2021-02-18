/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:49:29 by memartin          #+#    #+#             */
/*   Updated: 2021/02/12 15:17:35 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

int		main(void)
{
	std::cout << "\n##### TEST LIST #####\n" << std::endl;
	test_list();
	std::cout << "\n##### TEST VECTOR #####\n" << std::endl;
	test_vector();
	std::cout << "\n##### TEST STACK #####\n" << std::endl;
	test_stack();
	std::cout << "\n##### TEST QUEUE #####\n" << std::endl;
	test_queue();
	std::cout << "\n##### TEST MAP #####\n" << std::endl;
	test_map();
	return (0);
}
