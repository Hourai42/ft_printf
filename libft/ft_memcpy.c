/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:00:44 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 12:53:54 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	unsigned int	i;

	i = 0;
	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dst);
}
