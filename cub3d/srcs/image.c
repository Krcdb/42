#include "../includes/cub3d.h"

static int		get_color(t_data *d, int y)
{
	if (y < d->draw_start)
		return (d->c_color);
	else if (y >= d->draw_start && y <= d->draw_end)
	{
		if (d->side == 0)
		{
			if (d->pos_x < d->ray_x)
				return (W_C);
			else
				return (E_C);
		}
		else
		{
			if (d->pos_y < d->ray_y)
				return (NO_C);
			else
				return (SO_C);
		}
	}
	else
		return (d->f_color);
}

static void		put_pixel_to_img(t_data *d, int x, int y, int color)
{
	unsigned char *rgb;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	rgb = (unsigned char *)&color;
	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	d->img_data[y * d->s_l + x * d->bpp / 8] = r;
	d->img_data[y * d->s_l + x * d->bpp / 8 + 1] = g;
	d->img_data[y * d->s_l + x * d->bpp / 8 + 2] = b;
}

void			put_line_to_img(t_data *d, int x)
{
	int		color;
	int		y;

	y = 0;
	while (y < d->screen_y)
	{
		color = get_color(d, y);
		put_pixel_to_img(d, x, y, color);
		y++;
	}
}
