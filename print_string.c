/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 21:41:25 by ttran             #+#    #+#             */
/*   Updated: 2018/02/15 23:55:36 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*nullstring(void)
{
	char	*null;

	null = malloc(sizeof(char) * 7);
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	null[6] = '\0';
	return (null);
}

void		print_string(va_list *args, t_info *info)
{
	t_size	*size;

	if (info->modifier == L)
		print_wstring(args, info);
	else
	{
		set_str_size(&size, args);
		str_precision(size, info);
		filler(size, info);
		info->chars_printed += size->size;
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
		free_struct(&size);
	}
}
