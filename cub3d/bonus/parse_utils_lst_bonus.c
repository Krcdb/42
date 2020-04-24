/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_lst_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:34:44 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 13:14:30 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
