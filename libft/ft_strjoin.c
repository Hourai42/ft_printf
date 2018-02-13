/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:14:25 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 19:02:28 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		lens1;
	int		lens2;
	int		i;
	int		n;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens2 + lens1 + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	n = 0;
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (lens1 + lens2))
		str[i++] = s2[n++];
	str[i] = '\0';
	return (str);
}
