#include "../includes/cub3d.h"

int			is_map_char(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' ||
		c == 'W' || c == 'E')
		return (1);
	return (0);
}

int			is_map_line(char *line)
{
	while (*line)
	{
		if (!is_map_char(*line))
			return (0);
		line++;
	}
	return (1);
}

int			is_empty_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t')
			return (0);
		line++;
	}
	return (1);
}
