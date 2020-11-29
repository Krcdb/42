/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:24:15 by user42            #+#    #+#             */
/*   Updated: 2020/11/29 11:28:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
bool	easyfind(T &container, const int &n)
{
	typename T::iterator iterator = std::find(container.begin(), container.end(), n);
	return (iterator != container.end());
}

#endif