#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>

#define BUFF_SIZE 4096

typedef struct  s_struct
{
	char	buff[BUFF_SIZE];
	int		i_buff;
	int		ret;
	int		i_form;
	char	type;
	va_list	ap;

	size_t	width;
	size_t	precision;
	int		flag;
	int		pre_flag;
	int		h_mod;
	int		hh_mod;
	int		l_mod;
	int		ll_mod;
	int		j_mod;
	int		z_mod;
	int		zero_flag;
	int		hash_flag;
	int		plus_flag;
	int		minus_flag;
	int		sp_flag;
	int		per_flag;
	int		err;
}			t_moche;

int		ft_printf(const char *format, ...);
void	ft_data_init(t_moche *data);
void	ft_data_reset(t_moche *data);
void	ft_print_buff(t_moche *data);
void	ft_putchar_buff(t_moche *data, const char *form);
void	ft_put_conv(t_moche *data, char *s);
void	ft_parse(t_moche *data, const char *form);
void	ft_conv(t_moche *data);
void	ft_conv_s(t_moche *data);
void	ft_conv_c(t_moche *data, int n);
void	ft_conv_oux(t_moche *data);
void	ft_conv_di(t_moche *data);
void	ft_conv_p(t_moche *data);
void	ft_conv_majc(t_moche *data);
char	*ft_conv_uni(char *buff, int c);
char	*ft_imtoa(intmax_t n);
size_t	ft_intsize(intmax_t n);
size_t	ft_intsize_b(uintmax_t n, int base);
char	*ft_strjoinfree(char *s1, char *s2, int n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
void	ft_strdel(char **as);
char	*ft_strnew(size_t n);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
void	ft_putstr(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_utoa_b(uintmax_t n, int base);
char	*ft_toupper(char *s);
#endif
