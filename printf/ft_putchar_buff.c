#include "ft_printf.h"

void	ft_putchar_buff(t_moche *data, const char *form)
{
	data->buff[data->i_buff] = form[data->i_form];
	data->i_buff++;
	data->i_form++;
	data->ret++;
}
