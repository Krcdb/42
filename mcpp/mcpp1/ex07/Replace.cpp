/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:50:47 by memartin          #+#    #+#             */
/*   Updated: 2020/08/20 13:43:42 by memartin         ###   ########.fr       */
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
	if (this->m_s1 == this->m_s2)
	{
		std::cout << "s1 and s2 are the same\n";
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
	std::ofstream		outFlux;
	size_t				found;

	found = this->m_text.find(m_s1, 0);
	while (found != std::string::npos)
	{
		this->m_text.erase(found, this->m_s1.size());
		this->m_text.insert(found, this->m_s2);
		found = this->m_text.find(m_s1, found + this->m_s2.size());
	}
	outFlux.open(this->m_filePath.append(".replace"));
	if (outFlux)
		outFlux << this->m_text;
	else
		std::cout << "Error during file creation\n";
	return ;
}
