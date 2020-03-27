#include "libft.h"

char			*ft_strallocset(char c, size_t size)
{
	size_t		i;
	char		*str;
	char		*tmp;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	tmp = str;
	while (i <= size)
		tmp[i++] = '\0';
	i = 0;
	while (i < size)
		tmp[i++] = c;
	return (str);
}
