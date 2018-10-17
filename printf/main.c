/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 02:02:16 by mmartine          #+#    #+#             */
/*   Updated: 2018/10/17 22:50:23 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	printf("p res = %d\n", printf("%.0p, %.p", 0, 0));
	printf("f res = %d\n", ft_printf("%.0p, %.p", 0, 0));
	printf("p res = %d\n", printf("%.5p", 0));
	printf("f res = %d\n", ft_printf("%.5p", 0));
	printf("p res = %d\n", printf("%9.2p", 1234));
	printf("f res = %d\n", ft_printf("%9.2p", 1234));
	printf("p res = %d\n", printf("%9.2p", 1234567));
	printf("f res = %d\n", ft_printf("%9.2p", 1234567));
	printf("p res = %d\n", printf("%2.9p", 1234));
	printf("f res = %d\n", ft_printf("%2.9p", 1234));
	printf("p res = %d\n", printf("%2.9p", 1234567));
	printf("f res = %d\n", ft_printf("%2.9p", 1234567));

//	ft_printf("%-%d%d%s", 12, 6, "plop");
	return (0);
}
