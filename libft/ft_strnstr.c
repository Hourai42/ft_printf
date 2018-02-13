/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:06:41 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 13:03:51 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (*big && len != 0)
	{
		if (*big == *little)
		{
			if (len >= ft_strlen(little))
				if (ft_strequm(big, little) == 1)
					return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
