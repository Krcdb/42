/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:56:54 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/13 21:56:41 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if ((nb / 10) == 0)
		ft_putchar_fd((nb + '0'), fd);
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
}
