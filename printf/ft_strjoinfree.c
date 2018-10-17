/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:43:17 by mmartine          #+#    #+#             */
/*   Updated: 2018/10/02 12:08:03 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strjoinfree(char *s1, char *s2, int n)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char*)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strcat(ret, s2);
	if (n == 1)
		ft_strdel(&s1);
	else if (n == 2)
		ft_strdel(&s2);
	else if (n == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (ret);
}