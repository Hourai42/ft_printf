/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:20:05 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 17:41:40 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;

	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	while (n > 0)
	{
		if (*ps == (unsigned char)c)
		{
			*pd++ = *ps++;
			return (pd);
		}
		*pd++ = *ps++;
		n--;
	}
	return (NULL);
}
