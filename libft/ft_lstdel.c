/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:08:22 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 12:50:27 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *behind;

	while (*alst)
	{
		behind = *alst;
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(behind);
	}
}
