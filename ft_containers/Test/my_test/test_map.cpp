/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:27:48 by memartin          #+#    #+#             */
/*   Updated: 2021/02/12 15:15:33 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

template <typename T>
static void		print_map(T& map, std::string map_name) {
	std::cout << map_name << " : size " << map.size()<< std::endl;
	for (typename T::iterator it=map.begin(); it != map.end(); it++) {
		std::cout << "[" << it->first << "] : " << it->second << std::endl;
	}
	std::cout << std::endl;
}

void	test_map(void) {
	ft::Map<int, std::string> m1;
	ft::Map<int, std::string>::iterator it;
	ft::Map<int, std::string>::iterator it2;

	std::cout << "\n---insert---" << std::endl;
	m1.insert(std::pair<int, std::string>(21, "21"));
	m1.insert(std::pair<int, std::string>(10, "10"));
	m1.insert(std::pair<int, std::string>(30, "30"));
	m1.insert(std::pair<int, std::string>(15, "15"));
	m1.insert(std::pair<int, std::string>(5, "5"));
	m1.insert(std::pair<int, std::string>(9, "9"));
	m1.insert(std::pair<int, std::string>(3, "3"));
	m1.insert(std::pair<int, std::string>(1, "1"));
	m1.insert(std::pair<int, std::string>(25, "25"));
	m1.insert(std::pair<int, std::string>(45, "45"));
	m1.insert(std::pair<int, std::string>(50, "50"));
	m1.insert(std::pair<int, std::string>(60, "60"));
	m1.insert(std::pair<int, std::string>(41, "41"));
	print_map(m1, "m1");
	it = m1.begin();
	it2 = m1.end();
	++it;
	--it2;
	std::cout << "\n---m2(it + 1, it2 - 1)---" << std::endl;
	ft::Map<int, std::string> m2(it, it2);
	print_map(m2, "m2");

	std::cout << "\n---assign m2 = m1---" << std::endl;
	m2 = m1;
	print_map(m2, "m2");

	std::cout << "\n---test empty---" << std::endl;
	if (m1.empty())
		std::cout << "m1 is empty" << std::endl;
	else
		std::cout << "m1 not empty" << std::endl;

	std::cout << "\n---operator[10]---" << std::endl;
	std::cout << "m1[10] : " << m1[10] << std::endl;

	std::cout << "\n---operator[11] -> doesn't exit so it will be added---" << std::endl;
	m1[11];
	print_map(m1, "m1");
	std::cout << "\n---m1[11] = \"11\" -> doesn't exit so it will be added---" << std::endl;
	m1[11] = "11";
	print_map(m1, "m1");

	std::cout << "\n---erase 3---" << std::endl;
	it = m1.begin();
	++it;
	m1.erase(it);
	print_map(m1, "m1");

	std::cout << "\n---count, find and erase 21 then count 21---" << std::endl;
	it = m1.find(21);
	std::cout << "count(21) : " << m1.count(21) << std::endl;
	m1.erase(it);
	std::cout << "count(21) : " << m1.count(21) << std::endl;
	print_map(m1, "m1");
	std::cout << "count(21) : " << m1.count(21) << std::endl;

	std::cout << "\n---swap m1 m2---" << std::endl;
	print_map(m1, "m1");
	print_map(m2, "m2");
	m1.swap(m2);
	print_map(m1, "m1");
	print_map(m2, "m2");

	std::cout << "\n---lower and upper bound of 10---" << std::endl;
	std::cout << "lower_bound 10 : " << m1.lower_bound(10)->first << " | upper_bound 10 : " << m1.upper_bound(10)->first << std::endl;
	
	std::cout << "\n---lower and upper bound of 24---" << std::endl;
	std::cout << "lower_bound 24 : " << m1.lower_bound(24)->first << " | upper_bound 24 : " << m1.upper_bound(24)->first << std::endl;

	m1.clear();
	print_map(m1, "m1");
	return ;
}