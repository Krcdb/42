/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 02:02:16 by mmartine          #+#    #+#             */
/*   Updated: 2018/09/29 02:39:24 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
//	printf("p res = %d\n", printf("%4.15s", "42 is the answer"));
//	printf("f res = %d\n", ft_printf("%4.15s", "42 is the answer"));
//	ft_printf("\n");
//	ft_printf("%%\n");
//	ft_printf("%d\n", 42);
//	ft_printf("%d%d\n", 42, 41);
//	ft_printf("%d%d%d\n", 42, 43, 44);
//	ft_printf("%ld\n", 2147483647);
//	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
//	ft_printf("%X\n", 505);
//	ft_printf("%p\n", &ft_printf);
//	ft_printf("%20.15d\n", 54321);
//	ft_printf("%-10d\n", 3);
//	ft_printf("% d\n", 3);
//	ft_printf("%+d\n", 3);
//	ft_printf("%010d\n", 1);
//	ft_printf("%hhd\n", 0);
//	ft_printf("%jd\n", 9223372036854775807);
//	ft_printf("%zd\n", 4294967295);
//	ft_printf("%\n");
//	ft_printf("%U\n", 4294967295);
//	ft_printf("%u\n", 4294967295);
//	ft_printf("%o\n", 40);
//	ft_printf("%%#08x\n", 42);
//	ft_printf("%x\n", 1000);
//	ft_printf("%#X\n", 1000);
//	ft_printf("%s\n", NULL);
//	ft_printf("%S\n", L"ݗݜशব");
//	ft_printf("%s%s\n", "test", "test");
//	ft_printf("%s%s%s\n", "test", "test", "test");
//	ft_printf("%C\n", 15000);
	return (0);
}
