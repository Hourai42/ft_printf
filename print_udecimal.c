/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_udecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:23:46 by ttran             #+#    #+#             */
/*   Updated: 2018/02/13 15:23:47 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	unsigned_modifiers(va_list *args, int modifier)
{
	if (modifier == HH)
		return ((uintmax_t)(unsigned char)va_arg(*args, unsigned int));
	else if (modifier == H)
		return ((uintmax_t)(unsigned short)va_arg(*args, unsigned int));
	else if (modifier == L)
		return ((uintmax_t)va_arg(*args, unsigned long int));
	else if (modifier == LL)
		return ((uintmax_t)va_arg(*args, unsigned long long int));
	else if (modifier == J)
		return (va_arg(*args, uintmax_t));
	else if (modifier == Z)
		return ((uintmax_t)va_arg(*args, size_t));
	else
		return ((uintmax_t)va_arg(*args, unsigned int));
}

/*
** Just about everything unsigned ignores the "plus" or "blank" flags.
*/

void				print_udecimal(va_list *args, t_info *info)
{
	t_size			*size;
	uintmax_t		nbr;

	if (info->format_id == 'p')
		nbr = (unsigned long)va_arg(*args, void *);
	else if (info->format_id == 'O' || info->format_id == 'U')
		nbr = va_arg(*args, unsigned long int);
	else
		nbr = unsigned_modifiers(args, info->modifier);
	set_digit_size(&size, nbr, info);
	digit_precision(size, info);
	unumber_filler(size, info, nbr);
	info->chars_printed += size->size;
	leftjus(info, size);
	free_struct(&size);
}
