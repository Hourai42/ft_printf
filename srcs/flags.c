/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:26:37 by ttran             #+#    #+#             */
/*   Updated: 2018/02/16 17:26:49 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*sext(char format_id)
{
	char	*notsex;

	notsex = malloc(sizeof(char) * 3);
	notsex[2] = '\0';
	notsex[0] = '0';
	if (format_id == 'x' || format_id == 'p')
		notsex[1] = 'x';
	else
		notsex[1] = 'X';
	return (notsex);
}

void		hashtag_flag(t_size *size, t_info *info)
{
	char	*pasflag;
	char	*flaggednbr;

	if (info->format_id == 'o' || info->format_id == 'O')
	{
		pasflag = ft_strcreate(1, '0');
		flaggednbr = ft_strjoin(pasflag, size->fullchar);
		free(pasflag);
		free(size->fullchar);
		size->fullchar = flaggednbr;
		size->size++;
	}
	else if (info->format_id == 'x' || info->format_id == 'X' ||
	info->format_id == 'p')
	{
		pasflag = sext(info->format_id);
		flaggednbr = ft_strjoin(pasflag, size->fullchar);
		free(pasflag);
		free(size->fullchar);
		size->fullchar = flaggednbr;
		size->size += 2;
	}
}

void		blankplus_flags(t_size *size, t_info *info)
{
	char	*posflag;
	char	*flaggednbr;
	char	c;

	if (size->neg == -1)
		c = '-';
	else if (info->blank == 1)
		c = ' ';
	else
		c = '+';
	posflag = ft_strcreate(1, c);
	flaggednbr = ft_strjoin(posflag, size->fullchar);
	free(posflag);
	free(size->fullchar);
	size->fullchar = flaggednbr;
	size->size++;
}

void		leftjus(t_info *info, t_size *size)
{
	if (info->leftjus == 1)
	{
		ft_putstr(size->fullchar);
		ft_putstr(size->fill);
	}
	else
	{
		ft_putstr(size->fill);
		ft_putstr(size->fullchar);
	}
}
