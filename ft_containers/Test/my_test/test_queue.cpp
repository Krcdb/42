/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:11:50 by memartin          #+#    #+#             */
/*   Updated: 2021/02/03 17:14:15 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	test_queue(void) {
	ft::Queue<int> q1;

	std::cout << "\n---test empty and size---" << std::endl;
	std::cout << "empty : " << q1.empty() << std::endl;
	std::cout << "size : " << q1.size() << std::endl;

	std::cout << "\n---push 1->5 and display front/back each push---" << std::endl;
	q1.push(1);
	std::cout << "front : " << q1.front() << " || back : " << q1.back() << std::endl;
	q1.push(2);
	std::cout << "front : " << q1.front() << " || back : " << q1.back() << std::endl;
	q1.push(3);
	std::cout << "front : " << q1.front() << " || back : " << q1.back() << std::endl;
	q1.push(4);
	std::cout << "front : " << q1.front() << " || back : " << q1.back() << std::endl;
	q1.push(5);
	std::cout << "front : " << q1.front() << " || back : " << q1.back() << std::endl;
	
	std::cout << "\n---test empty and size---" << std::endl;
	std::cout << "empty : " << q1.empty() << std::endl;
	std::cout << "size : " << q1.size() << std::endl;

	std::cout << "\n---pop twice---" << std::endl;
	q1.pop();
	std::cout << "front : " << q1.front() << " || back : " << q1.back() << std::endl;
	std::cout << "size : " << q1.size() << std::endl;
	q1.pop();
	std::cout << "front : " << q1.front() << " || back : " << q1.back() << std::endl;
	std::cout << "size : " << q1.size() << std::endl;
}