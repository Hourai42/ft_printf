/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:51:05 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 19:06:52 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*p;
	t_list	*p2;
	t_list	*begin;

	if (lst == 0)
		return (NULL);
	begin = lst;
	new = f(begin);
	p = new;
	while (begin->next)
	{
		begin = begin->next;
		p2 = f(begin);
		p->next = p2;
		p = p->next;
	}
	p->next = NULL;
	return (new);
}
