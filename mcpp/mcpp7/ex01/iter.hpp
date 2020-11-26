/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:00:46 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 16:33:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	display(T const &item)
{
	std::cout << item << std::endl;
}

template <typename T>
void	iter(T array[], int length, void (*f)(T const &item))
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}

#endif