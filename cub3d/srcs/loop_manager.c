#include "../includes/cub3d.h"

int			loop_manager(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	raycast(d);
	key_manager(d);
	return (1);
}
