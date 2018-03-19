#include "ft_printf.h"

void	ft_data_init(t_moche *data, const char *form)
{
	data->i_buff = 0;
	data->ret = 0;
	data->i_form = 0;
	data->type = '0';
	ft_data_reset(data);
}
