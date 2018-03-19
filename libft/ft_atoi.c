/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:02:42 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/15 20:56:09 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int neg;
	int result;

	result = 0;
	neg = 1;
	while ((*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
				*str == '\f' || *str == '\r') && *str)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
		result = (result * 10) + (*str++ - 48);
	return (result * neg);
}
