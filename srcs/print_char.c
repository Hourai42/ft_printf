/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 20:24:42 by ttran             #+#    #+#             */
/*   Updated: 2018/02/12 20:24:44 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_char(va_list *args, t_info *info)
{
	t_size	*size;

	set_single_size(&size);
	filler(size, info);
	info->chars_printed += size->size;
	if (info->leftjus == 1)
	{
		ft_putchar((unsigned char)va_arg(*args, int));
		ft_putstr(size->fill);
	}
	else
	{
		ft_putstr(size->fill);
		ft_putchar((unsigned char)va_arg(*args, int));
	}
	free_struct(&size);
}
