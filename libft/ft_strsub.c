/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:57:27 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 19:02:06 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	if (s == 0)
		return (NULL);
	p = malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && len)
	{
		p[i] = s[start];
		start++;
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}
