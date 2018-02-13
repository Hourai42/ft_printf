/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:28:52 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 21:38:02 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	char	*p;

	n = -1;
	i = 0;
	if (s == 0)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
		return (ft_strdup(s));
	while (s[i + 1] != '\0')
		i++;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s)
		i--;
	p = malloc(sizeof(char) * (i + 2));
	if (p == 0)
		return (NULL);
	while (++n <= i)
		p[n] = s[n];
	p[n] = '\0';
	return (p);
}
