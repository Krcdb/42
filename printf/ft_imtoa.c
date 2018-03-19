#include "ft_printf.h"


char		*ft_imtoa(intmax_t n)
{
	size_t	size;
	char	*res;
	int		neg;

	size = ft_intsize(n);
	neg = 0;
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	if (!(res = (char*)malloc((sizeof *res) * size + 1)))
		return (NULL);
	while (--size)
	{
		res[size] = (n % 10) + 48;
		n /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
