/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:19:47 by memartin          #+#    #+#             */
/*   Updated: 2020/02/04 18:19:49 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;

	if (s1 && s2)
	{
		if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		res = ft_strcat(res, s1);
		res = ft_strcat(res, s2);
		return (res);
	}
	return (NULL);
}
