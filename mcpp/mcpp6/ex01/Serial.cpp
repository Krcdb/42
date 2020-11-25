/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serial.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:56:56 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 18:23:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serial.hpp"

void		*serialize(void)
{

	static std::string alphabet = "0123456789abcdefghijklmopqrstuvxyzABCDEFGHIJKLMOPQRSTUVXYZ";
	static int alen = alphabet.length();
	char *raw;
	char c;

	raw = new char[20];
	std::cout << "raw s1 : ";
	for (int i = 0; i < 8; i++)
	{
		c = alphabet[rand() % alen];
		raw[i] = c;
		std::cout << c;
	}
	int nb = rand() % 123456789;
	std::cout << std::endl << "raw n  : " << nb << std::endl;
	*reinterpret_cast<int*>(raw + 8) = nb;
	std::cout << "raw s2 : ";
	for (int i = 0; i < 8; i++)
	{
		c = alphabet[rand() % alen];
		raw[i + 12] = c;
		std::cout << c;
	}
	std::cout << std::endl;
	return (raw);
}

Data		*deserialize(void *raw)
{
	Data *data = new Data;

	data->s1 = std::string(reinterpret_cast<char*>(raw), 8);
	data->n = *reinterpret_cast<int*>(reinterpret_cast<char*>(raw) + 8);
	data->s2 = std::string(reinterpret_cast<char*>(raw) + 12, 8);
	return (data);
}