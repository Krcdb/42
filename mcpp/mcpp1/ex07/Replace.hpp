/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:34:59 by memartin          #+#    #+#             */
/*   Updated: 2020/08/20 13:18:48 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <iostream>
# include <fstream>

class		Replace
{
	private:
		std::string		m_filePath;
		std::string		m_text;
		std::string		m_s1;
		std::string		m_s2;

	public:
		Replace();
		Replace(std::string filePath, std::string s1, std::string s2);
		virtual ~Replace();

		int			checkArgsAndRead();
		void		replaceText();
};

#endif
