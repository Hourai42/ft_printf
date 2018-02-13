/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:34:48 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 21:54:35 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	link = malloc(sizeof(t_list));
	if (link == 0)
		return (NULL);
	if (content == 0)
	{
		link->content = NULL;
		content_size = 0;
		link->next = NULL;
		return (link);
	}
	link->content = malloc(content_size);
	link->content_size = content_size;
	ft_memcpy(link->content, content, content_size);
	link->next = NULL;
	return (link);
}
