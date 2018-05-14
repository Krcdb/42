/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 02:02:16 by mmartine          #+#    #+#             */
/*   Updated: 2018/05/14 23:33:07 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{//	printf("\np res = %d\n", printf("p u{%4.2s}s {%-10.s}\n {%---5.3s}\n" , "coco", NULL, "yooo"));
//	printf("\nf res = %d\n", ft_printf("f u{%4.2s}s {%-10.s}\n {%---5.3s}\n", "coco", NULL, "yooo"));
//	printf("p res = %d\n", printf("{% 20.12ld} et {% 05D}{% 4.8hi} !\n", 0x11ffaa147, 24, (short)-2345));
//	printf("f res = %d\n", ft_printf("{% 20.12ld} et {% 05D}{% 4.8hi} !\n", 0x11ffaa147, 24, (short)-2345));
	printf("f res = %d\n", ft_printf("ble lbe %% {%#-10.8O} {%#01.6x}\n", 123, 123));
	printf("f res = %d\n", printf("ble lbe %% {%#-10.8O} {%#01.6x}\n", 123, 123));
	return (0);
}
