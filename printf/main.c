/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 02:02:16 by mmartine          #+#    #+#             */
/*   Updated: 2018/05/18 00:47:24 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{//	printf("\np res = %d\n", printf("p u{%4.2s}s {%-10.s}\n {%---5.3s}\n" , "coco", NULL, "yooo"));
//	printf("\nf res = %d\n", ft_printf("f u{%4.2s}s {%-10.s}\n {%---5.3s}\n", "coco", NULL, "yooo"));
//	printf("p res = %d\n", printf("{% 20.12ld} et {% 05D}{% 4.8hi} !\n", 0x11ffaa147, 24, (short)-2345));
//	printf("f res = %d\n", ft_printf("{% 20.12ld} et {% 05D}{% 4.8hi} !\n", 0x11ffaa147, 24, (short)-2345));
	printf("f res = %d\n", ft_printf("\n{%024hho} et{%#1.2o} {%0012.O}\n", (unsigned char)12, 0, 123654789));
	printf("p res = %d\n", printf("\n{%024hho} et{%#1.2o} {%0012.O}\n", (unsigned char)12, 0, 123654789));
	return (0);
}
