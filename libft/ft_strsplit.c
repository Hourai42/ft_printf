/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:59:40 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 19:05:20 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**fuck;
	int		count;
	int		i;
	int		n;

	n = 0;
	i = 0;
	if (s == 0)
		return (NULL);
	count = ft_nmbwrd((char *)s, c);
	fuck = (char **)malloc(sizeof(char *) * (count + 1));
	if (fuck == 0)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
			fuck[n++] = ft_mallocwrd((char *)s, i, c);
		while (s[i] != c && s[i])
			i++;
		if (s[i] != '\0')
			i++;
	}
	fuck[n] = 0;
	return (fuck);
}
