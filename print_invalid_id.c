/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:42:50 by ttran             #+#    #+#             */
/*   Updated: 2018/02/12 18:42:51 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** A trial for the real "print" function. Create a struct to handle
** width/precision and such.
*/

void	print_invalid_id(t_info *info)
{
	t_size *size;

	set_single_size(&size);
	filler(size, info);
	info->chars_printed += size->size;
	if (info->leftjus == 1)
	{
		ft_putchar(info->format_id);
		ft_putstr(size->fill);
	}
	else
	{
		ft_putstr(size->fill);
		ft_putchar(info->format_id);
	}
	free_struct(&size);
}
