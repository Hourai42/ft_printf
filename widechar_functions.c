/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widechar_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:06:10 by ttran             #+#    #+#             */
/*   Updated: 2018/02/16 17:06:11 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** An intentionally crippled version of ft_putwchar.
*/

void		ft_putwchar(wchar_t c)
{
	write(1, &c, 1);
}

void		ft_putwstr(wchar_t *str)
{
	while (*str)
	{
		ft_putwchar(*str);
		str++;
	}
}

int			ft_wstrlen(wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

wchar_t		*ft_wstrdup(wchar_t *str)
{
	int		i;
	wchar_t	*s2;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	s2 = malloc(sizeof(wchar_t) * (i + 1));
	i = 0;
	while (str[i])
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
