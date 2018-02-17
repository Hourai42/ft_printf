/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullshit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:13:18 by ttran             #+#    #+#             */
/*   Updated: 2018/02/16 18:13:25 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strduplegit(char *str)
{
	int		i;
	char	*s2;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\0')
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*ft_strcreate(int size, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (NULL);
	while (i < size)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

static void	handle_single(t_size *size, t_info *info)
{
	if (size->neg == -1)
		size->fullchar[0] = '-';
	else if (info->plus == 1)
		size->fullchar[0] = '+';
	else
		size->fullchar[0] = ' ';
}

void		handle_bullshit(t_size *size, t_info *info, int shit)
{
	char	*shitty;
	char	*paddednbr;

	shitty = ft_strcreate(info->width - size->size, '0');
	paddednbr = ft_strjoin(shitty, size->fullchar);
	free(shitty);
	free(size->fullchar);
	size->fullchar = paddednbr;
	size->size += info->width - size->size;
	if (shit == 1)
		handle_single(size, info);
	else if (shit == 2)
	{
		if (info->format_id == 'X')
			size->fullchar[1] = 'X';
		else
			size->fullchar[1] = 'x';
	}
}
