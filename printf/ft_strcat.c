/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:50:06 by mmartine          #+#    #+#             */
/*   Updated: 2018/09/29 00:44:39 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int len;

	len = 0;
	while (*s1 != '\0')
	{
		s1++;
		len++;
	}
	while (*s2 != '\0')
	{
		*s1++ = *s2++;
		len++;
	}
	*s1 = '\0';
	s1 -= len;
	return (s1);
}