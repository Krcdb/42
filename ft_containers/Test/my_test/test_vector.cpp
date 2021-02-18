/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:59:50 by user42            #+#    #+#             */
/*   Updated: 2021/02/09 11:32:20 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

template <typename T>
static void		print_vector(T& vct, std::string vct_name) {
	std::cout << vct_name << " : size " << vct.size()<< std::endl;
	for (typename T::iterator it=vct.begin(); it != vct.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	test_vector(void)
{
	size_t n = 10;
	int nb = 5;

	ft::Vector<int> v1(n, nb);
	ft::Vector<int>::iterator it1 = v1.begin();
	ft::Vector<int>::iterator it2 = v1.end();

	std::cout << "\n---iterator comparison---" << std::endl;
	if (it1 < it2)
		std::cout << "\nit1 < it2" << std::endl;
	else
		std::cout << "\nit2 <= it1" << std::endl;

	std::cout << "\n---constructor---" << std::endl;
	print_vector(v1, "v1");
	ft::Vector<int> v2(it1, it2);
	print_vector(v2, "v2");
	v2.clear();

	std::cout << "\n---clear v2---" << std::endl;
	print_vector(v2, "v2");

	std::cout << "\n---v2 = v1---" << std::endl;
	v2 = v1;
	print_vector(v2, "v2");

	std::cout << "\n---clear and push_back 0->15---" << std::endl;
	v2.clear();
	for (int i = 0; i < 16; i++)
		v2.push_back(i);
	print_vector(v2, "v2");
	
	std::cout << "\n---print capacity and size---" << std::endl;
	std::cout << "capacity : " << v2.capacity() << std::endl;
	std::cout << "size : " << v2.size() << std::endl;

	std::cout << "\n---resize to 5 then 11 then check capacity---" << std::endl;
	v1.resize(5, 7);
	print_vector(v1, "v1");
	v1.resize(11, 7);
	print_vector(v1, "v1");
	std::cout << "capacity : " << v1.capacity() << std::endl;

	std::cout << "\n---reserve 100 again then check capacity---" << std::endl;
	v1.reserve(100);
	std::cout << "capacity : " << v1.capacity() << std::endl;
	
	std::cout << "\n---acces front back , at(5) then [5]---" << std::endl;
	std::cout << "font : " << v2.front() << std::endl;
	std::cout << "back : " << v2.back() << std::endl;
	std::cout << "at(5) : " << v2.at(5) << std::endl;
	std::cout << "[5] : " << v2[5] << std::endl;
	
	std::cout << "\n---both assigns are used in there constructor---" << std::endl;
	
	std::cout << "\n---insert one (30) at [end - 5]---" << std::endl;
	it2 = v1.end();
	it2 -= 5;
	it2 = v1.insert(it2, 30);
	print_vector(v1, "v1");

	std::cout << "\n---insert 10 (42) at [end - 5]---" << std::endl;
	it2 = v1.end();
	it2 -= 5;
	v1.insert(it2, n, 42);
	print_vector(v1, "v1");

	std::cout << "\n---insert all v2 at [end - 5]---" << std::endl;
	it2 = v1.end();
	it2 -= 5;
	v1.insert(it2, v2.begin(), v2.end());
	print_vector(v1, "v1");

	std::cout << "\n---erase position [end - 6] (15)---" << std::endl;
	v1.erase(v1.end() - 6);
	print_vector(v1, "v1");

	std::cout << "\n---swap v1 v2---" << std::endl;
	v1.swap(v2);
	print_vector(v1, "v1");
	print_vector(v2, "v2");
	return ;
}