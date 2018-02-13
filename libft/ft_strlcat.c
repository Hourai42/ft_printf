/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:17:55 by ttran             #+#    #+#             */
/*   Updated: 2017/12/03 23:29:17 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t		i;
	size_t		t1;
	size_t		t2;

	i = 0;
	t1 = ft_strlen(dst);
	t2 = ft_strlen(src);
	if (size == 0)
		return (t2);
	if (size - 1 < t1)
		return (t2 + size);
	while (t1 + i < size - 1)
	{
		dst[t1 + i] = src[i];
		i++;
	}
	dst[t1 + i] = '\0';
	return (t1 + t2);
}
