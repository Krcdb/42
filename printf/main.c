/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 02:02:16 by mmartine          #+#    #+#             */
/*   Updated: 2018/06/13 20:34:06 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	char c;
	printf("p res = %d\n", printf("%4.15s", "42 is the answer"));
	printf("f res = %d\n", ft_printf("%4.15s", "42 is the answer"));
	return (0);
}
