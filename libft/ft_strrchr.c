/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:33:46 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 20:45:09 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			*s;
	int				len;

	s = (char *)str;
	i = ft_strlen(str);
	len = (int)i;
	while (len >= 0)
	{
		if (s[len] == c)
			return (s + len);
		len--;
	}
	return (NULL);
}
