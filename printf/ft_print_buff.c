#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	while(*str)
		ft_putchar(*str++);
}

void		ft_print_buff(t_moche *data)
{
	data->buff[data->i_buff] = '\0';
	ft_putstr(data->buff);
	bzero(data->buff, BUFF_SIZE);
	data->i_buff = 0;
}
