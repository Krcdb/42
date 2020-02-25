/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:54:38 by mmartine          #+#    #+#             */
/*   Updated: 2019/10/08 13:25:48 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <ctype.h>
# include <limits.h>

# define BUFF_SIZE 4096

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct	s_struct
{
	char		buff[BUFF_SIZE];
	int			i_buff;
	int			ret;
	int			i_form;
	char		type;
	va_list		ap;

	size_t		width;
	size_t		precision;
	int			flag;
	int			pre_flag;
	int			h_mod;
	int			hh_mod;
	int			l_mod;
	int			ll_mod;
	int			j_mod;
	int			z_mod;
	int			zero_flag;
	int			hash_flag;
	int			plus_flag;
	int			minus_flag;
	int			sp_flag;
	int			per_flag;
	int			err;
	int			mod_flag;
}				t_moche;

void			ft_conv(t_moche *data);
char			*ft_strjoinfree(char *s1, char *s2, int n);
void			ft_conv_s(t_moche *data);
void			ft_conv_c(t_moche *data, int n);
void			ft_conv_oux(t_moche *data);
void			ft_conv_di(t_moche *data);
void			ft_conv_p(t_moche *data);
void			ft_conv_majc(t_moche *data);
void			ft_conv_majs(t_moche *data);
char			*ft_conv_uni(char *buff, int c);
int				ft_conv_c_norm(t_moche *d, char c);
int				ft_printf(const char *format, ...);
void			ft_parse(t_moche *data, const char *form);
void			ft_putchar_buff(t_moche *data, const char *form);
void			ft_put_conv(t_moche *data, char *s);
void			ft_print_buff(t_moche *data);
void			ft_set_flag(t_moche *data);
void				ft_bzero(void *s, size_t n);
void			ft_data_init(t_moche *data);
void			ft_data_reset(t_moche *data);
char			*ft_imtoa(intmax_t n);
char			*ft_utoa_b(uintmax_t n, int base);
size_t			ft_intsize(intmax_t n);
size_t			ft_intsize_b(uintmax_t n, int base);
int				ft_conv_c_norm(t_moche *d, char c);
int				setbase(t_moche *d);
int				ft_set_width_pre_s_norm(t_moche *d, char *s);
char			*ft_set_oux_norm(t_moche *data, char *s, char *tmp);
int				ft_check_mod_norm(t_moche *data, const char *form);
int				ft_printf(const char *format, ...);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_toupper(char *c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putendl(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alsr, t_list *nlist);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					*ft_sort_number(int *tab, int len);
void				ft_puttab(char **tab);
char				**ft_sort_tab(char **tab);
int					ft_sqrt(int nb);
void				ft_putnbr_endl(int nbr);
size_t				ft_lstlen(t_list *lst);

#endif
