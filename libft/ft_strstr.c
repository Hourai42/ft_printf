/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:39:39 by ttran             #+#    #+#             */
/*   Updated: 2017/12/04 19:34:07 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (*big)
	{
		if (*big == *little)
		{
			if (ft_strequm(big, little) == 1)
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
