/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:47:09 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 12:54:14 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;
	int				i;

	i = len - 1;
	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (i >= 0)
		{
			pd[i] = ps[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
