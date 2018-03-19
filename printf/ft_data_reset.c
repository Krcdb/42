#include "ft_printf.h"

void	ft_data_reset(t_moche *data)
{
	data->type = '0';
	data->width = 0;
	data->precision = 0;
	data->h_mod = 0;
	data->hh_mod = 0;
	data->l_mod = 0;
	data->ll_mod = 0;
	data->j_mod = 0;
	data->z_mod = 0;
	data->zero_flag = 0;
	data->hash_flag = 0;
	data->plus_flag = 0;
	data->minus_flag = 0;
	data->sp_flag = 0;
}
