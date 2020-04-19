#include "../includes/cub3d.h"

void			print_lst(t_maplist *mlst)
{
	int i = 0;
	if (mlst == NULL)
	{
		ft_printf("no lst\n");
		return ;
	}
	while (mlst->next)
	{
		ft_printf("line : %2d  || {%s}\n", i++, mlst->content);
		mlst = mlst->next;
	}
	ft_printf("line : %2d  || {%s}\n", i++, mlst->content);
}

t_maplist		*newlst(const char *content, size_t content_size)
{
	t_maplist	*new;

	if (!(new = (t_maplist*)malloc(sizeof(t_maplist))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content_size = content_size;
		new->content = ft_strdup(content);
	}
	new->next = NULL;
	return (new);
}

void			lstaddend(t_maplist **hlst, t_maplist *nlst)
{
	t_maplist	*tmp;

	tmp = *hlst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nlst;
}

size_t			get_nb_line(t_maplist *hlst)
{
	size_t		res;

	res = 0;
	while (hlst->next)
	{
		res++;
		hlst = hlst->next;
	}
	res++;
	return (res);
}

size_t			get_longest_line(t_maplist *hlst)
{
	size_t		res;

	res = 0;
	while (hlst->next)
	{
		if (res < hlst->content_size)
			res = hlst->content_size;
		hlst = hlst->next;
	}
	if (res < hlst->content_size)
		res = hlst->content_size;
	return (res);
}

void			lstdel(t_maplist **hlst)
{
	t_maplist	*tmp;

	if (hlst == NULL || *hlst == NULL)
		return ;
	while ((*hlst)->next)
	{
		tmp = (*hlst)->next;
		if ((*hlst)->content)
			free((*hlst)->content);
		free(*hlst);
		*hlst = tmp;
	}
	if ((*hlst)->content)
		free((*hlst)->content);
	free(*hlst);
	*hlst = NULL;
}
