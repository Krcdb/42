/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_boi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:06:14 by memartin          #+#    #+#             */
/*   Updated: 2020/07/29 15:26:48 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		atoi_boi(const char *str)
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
