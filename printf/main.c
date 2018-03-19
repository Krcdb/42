#include "ft_printf.h"

int main()
{

printf("res : %s\n", ft_imtoa(-24432525123456789));

	ft_printf("ft_printf || bonjour %s %s  %%\n", "Michel", "fdp");
	printf("printf    || bonjour %s %s  %%\n\n", "Michel", "fdp");

	ft_printf("ft_printf || bonjour %10.3s %1s  %%\n", "Michel", "fdp");
	printf("printf    || bonjour %10.3s %1s  %%\n\n", "Michel", "fdp");

	ft_printf("ft_printf || bonjour %10.3s %-5s  %%\n", "Michel", "fdp");
	printf("printf    || bonjour %10.3s %-5s  %%\n\n", "Michel", "fdp");

	ft_printf("ft_printf || bonjour %-10.3s %s  %%\n", "Michel", "fdp");
	printf("printf    || bonjour %-10.3s %s  %%\n\n", "Michel", "fdp");

	ft_printf("ft_printf || bonjour %5c %-5c  %%\n", 'M', 'f');
	printf("printf    || bonjour %5c %-5c  %%\n\n", 'M', 'f');
return (0);
}
