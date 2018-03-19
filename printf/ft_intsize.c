#include "ft_printf.h"

size_t		ft_intsize(intmax_t n)
{
	size_t size;

	size = 0;
	if (n == 0)
		return (0);
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}
