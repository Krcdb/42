/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:00:40 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/18 01:10:49 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*new;
	size_t		lsize;
	void		*lcontent;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		content_size = 0;
	}
	else
	{
		if (!(lcontent = malloc(content_size)))
			return (NULL);
		lcontent = ft_memcpy(lcontent, content, content_size);
		lsize = content_size;
		new->content_size = lsize;
		new->content = lcontent;
	}
	new->next = NULL;
	return (new);
}
