#include "ft_printf.h"

void		ft_conv(t_moche *data)
{
	if (data->type == 's')
		ft_conv_s(data);
	else if (data->type == 'c')
		ft_conv_c(data);
}
