/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:50:47 by memartin          #+#    #+#             */
/*   Updated: 2020/08/20 13:20:15 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(){
}

Replace::Replace(std::string filePath, std::string s1, std::string s2):
	m_filePath(filePath), m_s1(s1), m_s2(s2)
{
	m_text = "";
}

Replace::~Replace(){
}

int
Replace::checkArgsAndRead(){
	std::ifstream		inFlux;
	std::string			line;

	if (this->m_s1.size() == 0)
	{
		std::cout << "s1 is empty\n";
		return (1);
	}
	if (this->m_s2.size() == 0)
	{
		std::cout << "s2 is empty\n";
		return (1);
	}
	inFlux.open(this->m_filePath);
	if (inFlux)
	{
		while (getline(inFlux, line))
		{
			this->m_text.append(line);
			this->m_text.append("\n");
		}
		std::cout << "text : \n" << m_text << std::endl;
	}
	else
	{
		std::cout << "Error during file opening\n";
		return (1);
	}
	return (0);
}

void
Replace::replaceText()
{
	return ;
}
