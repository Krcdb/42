/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:56:24 by memartin          #+#    #+#             */
/*   Updated: 2020/07/29 15:26:17 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static size_t	ft_strlen(const char *s)
{
	int l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

static char		*ft_strdup(const char *src)
{
	char *res;
	char *tmp;

	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	tmp = res;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (res);
}

static size_t	ft_intmaxsize(intmax_t n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char		*ft_strnew(size_t size)
{
	char	*str;
	int		len;

	len = size;
	if (!(str = (char*)malloc(sizeof(*str) * size + 1)))
		return (NULL);
	while (len--)
		*str++ = '\0';
	*str = '\0';
	str -= size;
	return (str);
}

char			*ft_ltoa(intmax_t n)
{
	char		*res;
	size_t		len;

	len = ft_intmaxsize(n);
	res = ft_strnew(len);
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (!res)
		return (NULL);
	len--;
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
