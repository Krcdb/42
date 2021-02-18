/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:50:06 by memartin          #+#    #+#             */
/*   Updated: 2021/02/12 15:53:40 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

template <typename T>
static void		print_list(T& lst, std::string lst_name)
{
	std::cout << lst_name << " : size " << lst.size()<< std::endl;
	for (typename T::iterator it=lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

bool bigger_than(const int &n1, const int &n2) { return (n1 > n2); }

bool more_than_five(const int &n1, const int &n2) { 
	int res = n1 - n2;
	return (res > 5); 
}

void			test_list(void)
{
	ft::List<int> base;

	base.push_back(9);
	base.push_back(10);
	base.push_front(8);
	base.push_front(7);
	base.push_front(6);
	base.push_front(5);
	base.push_front(4);
	base.push_front(3);
	base.push_front(2);
	base.push_front(1);
	print_list(base, "base");
	ft::List<int>::iterator base_bit = base.begin();
	ft::List<int>::iterator base_eit = base.end();
	ft::List<int> lst(base_bit, base_eit);

	std::cout << "\n---lst(first, last)---" << std::endl;
	print_list(lst, "lst");

	std::cout << "\n---pop frint and back---" << std::endl;
	lst.pop_back();
	lst.pop_front();
	print_list(lst, "lst");

	std::cout << "\n---erase begin + 1 to end - 1---" << std::endl;
	ft::List<int>::iterator it1 = lst.begin();
	ft::List<int>::iterator it2 = lst.end();
	it1++; it2--;
	lst.erase(it1, it2);
	print_list(lst, "lst");
	
	std::cout << "\n---insert base in lst---" << std::endl;
	it1 = lst.begin();
	lst.insert(it2, base_bit, base_eit);
	print_list(lst, "lst");

	std::cout << "\n---swap---" << std::endl;
	lst.swap(base);
	print_list(lst, "lst");
	print_list(base, "base");	
	lst.swap(base);
	print_list(lst, "lst");
	print_list(base, "base");
	
	std::cout << "\n---resize 20---" << std::endl;
	lst.resize(20, 20);
	print_list(lst, "lst");
	std::cout << "\n---resize 10---" << std::endl;
	lst.resize(10, 20);
	print_list(lst, "lst");

	std::cout << "\n---splice---" << std::endl;
	it1 = lst.end();
	lst.splice(it1, base);
	print_list(lst, "lst");
	print_list(base, "base");
	it1 = lst.begin();
	ft::advance(it1, 10);
	base_bit = base.begin();
	base.splice(base_bit, lst, it1, lst.end());
	print_list(lst, "lst");
	print_list(base, "base:");

	std::cout << "\n---remove 3---" << std::endl;
	lst.remove(3);
	print_list(lst, "lst");

	std::cout << "\n---remove if odd---" << std::endl;
	lst.remove_if(is_odd());
	print_list(lst, "lst");

	std::cout << "\n---sort---" << std::endl;
	lst.push_back(4);
	lst.push_back(4);
	lst.push_back(4);
	lst.push_back(8);
	lst.push_back(6);
	print_list(lst, "lst");
	lst.sort();
	print_list(lst, "lst");	
	lst.sort(bigger_than);
	print_list(lst, "lst");
	
	std::cout << "\n---unique---" << std::endl;
	lst.unique();
	print_list(lst, "lst");
	lst.push_back(80);
	lst.push_back(15);
	lst.push_back(7);
	lst.push_back(12);
	lst.push_back(17);
	lst.push_back(30);
	lst.push_back(50);
	lst.sort();

	std::cout << "\n---unique more than 5---" << std::endl;
	print_list(lst, "lst");
	lst.unique(more_than_five);
	print_list(lst, "lst");

	std::cout << "\n---merge---" << std::endl;
	print_list(lst, "lst");
	print_list(base, "base");
	lst.merge(base);
	print_list(lst, "lst");
	print_list(base, "base");
	lst.clear();
	for (int i = 1; i < 10; i++) {
		lst.push_back(i * 2);
	}
	base.clear();
	for (int i = 1; i < 10; i++) {
		base.push_back(i * 3);
	}


	std::cout << "\n---merge/sort comp with bigger than---" << std::endl;
	print_list(lst, "lst");
	print_list(base, "base");
	lst.sort(bigger_than);
	base.sort(bigger_than);
	print_list(lst, "lst");
	print_list(base, "base");
	lst.merge(base, bigger_than);
	print_list(lst, "lst");
	print_list(base, "base");

	std::cout << "\n---reverse---" << std::endl;
	lst.reverse();
	print_list(lst, "lst");
	lst.pop_back();
	lst.reverse();
	print_list(lst, "lst");
	
	std::cout << "\n---relationnal operator---" << std::endl;
	ft::List<int> l1;
	ft::List<int> l2;
	for (int i = 1; i < 3; i++) {
		l1.push_back(i);
		l2.push_back(i);
	}
	print_list(l1, "l1");
	print_list(l2, "l2");
	if (l1 == l2)
		std::cout << "list are equal" << std::endl;
	else
		std::cout << "list are not equal" << std::endl;
	print_list(lst, "lst");
	print_list(base, "base");
	if (lst == base)
		std::cout << "list are equal" << std::endl;
	else
		std::cout << "list are not equal" << std::endl;
	
	std::cout << "\n---swap non member---" << std::endl;
	ft::swap(lst, base);
	print_list(lst, "lst");
	print_list(base, "base");
}
