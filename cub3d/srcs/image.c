#include "../includes/cub3d.h"

static int		get_color(t_data *d, int y)
{
	if (y < d->draw_start)
		return (d->c_color);
	else if (y >= d->draw_start && y <= d->draw_end)
	{
		if (d->side == 0)
			return (EA_C);
		else if (d->side == 1)
			return (WE_C);
		else if (d->side == 2)
			return (SO_C);
		else
			return (NO_C);
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
	int		y;

	y = 0;
	while (y < d->draw_start)
		put_pixel_to_img(d, x, y++, d->c_color);
	y = d->draw_end + 1;
	while (y < d->screen_y)
		put_pixel_to_img(d, x, y++, d->f_color);
	put_texture_on_img(d, x, get_texture_data(d));
}
