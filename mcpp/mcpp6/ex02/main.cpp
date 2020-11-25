/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:09:43 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 19:16:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		Base *p;
		p = creatClass();
		identify_from_pointer(p);
		identify_from_reference(*p);
		delete p;
	}
}