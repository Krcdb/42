/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:40:29 by fcadet            #+#    #+#             */
/*   Updated: 2021/02/15 11:16:59 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map.hpp"

void	nmap::test_map(void)
{
	std::cout << "start map" << std::endl;
	std::pair<std::string, int>		str_int_init[] = { std::make_pair("Bravo", 2),
													   std::make_pair("Alpha", 1),
													   std::make_pair("Delta", 4),
													   std::make_pair("Echo", 5),
													   std::make_pair("Golf", 7),
													   std::make_pair("Charlie", 3),
													   std::make_pair("Foxtrot", 6) };
	std::pair<int, std::string>		int_str_init[] = { std::make_pair(2, "Bravo"),
													   std::make_pair(1, "Alpha"),
													   std::make_pair(4, "Delta"),
													   std::make_pair(5, "Echo"),
													   std::make_pair(7, "Golf"),
													   std::make_pair(3, "Charlie"),
													   std::make_pair(6, "Foxtrot") };
													   
	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_const<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_const<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mITERATORS :\n";
	test_iter<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_iter<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mCAPACITY :\n";
	test_capacity<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_capacity<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mACCESS :\n";
	test_access<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_access<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mMODIFIERS :\n";
	test_mod<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_mod<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mOBSERVERS :\n";
	test_obs<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_obs<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mOPERATIONS :\n";
	test_op<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_op<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");
}
