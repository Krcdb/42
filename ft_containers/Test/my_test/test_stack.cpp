/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:20:20 by memartin          #+#    #+#             */
/*   Updated: 2021/02/03 17:06:36 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	test_stack(void) {
	ft::Stack<int> s1;

	std::cout << "\n---test empty and size---" << std::endl;
	std::cout << "empty : " << s1.empty() << std::endl;
	std::cout << "size : " << s1.size() << std::endl;

	std::cout << "\n---push 1->5 and display top each push---" << std::endl;
	s1.push(1);
	std::cout << "top : " << s1.top() << std::endl;
	s1.push(2);
	std::cout << "top : " << s1.top() << std::endl;
	s1.push(3);
	std::cout << "top : " << s1.top() << std::endl;
	s1.push(4);
	std::cout << "top : " << s1.top() << std::endl;
	s1.push(5);
	std::cout << "top : " << s1.top() << std::endl;
	
	std::cout << "\n---test empty and size---" << std::endl;
	std::cout << "empty : " << s1.empty() << std::endl;
	std::cout << "size : " << s1.size() << std::endl;

	std::cout << "\n---pop twice---" << std::endl;
	s1.pop();
	std::cout << "top : " << s1.top() << std::endl;
	std::cout << "size : " << s1.size() << std::endl;
	s1.pop();
	std::cout << "top : " << s1.top() << std::endl;
	std::cout << "size : " << s1.size() << std::endl;
}