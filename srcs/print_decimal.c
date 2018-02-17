/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:58:41 by ttran             #+#    #+#             */
/*   Updated: 2018/02/13 11:58:42 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	signed_modifiers(va_list *args, int modifier)
{
	if (modifier == HH)
		return ((intmax_t)(signed char)va_arg(*args, signed int));
	else if (modifier == H)
		return ((intmax_t)(signed short)va_arg(*args, signed int));
	else if (modifier == L)
		return ((intmax_t)va_arg(*args, signed long));
	else if (modifier == LL)
		return ((intmax_t)va_arg(*args, signed long long));
	else if (modifier == J)
		return (va_arg(*args, intmax_t));
	else if (modifier == Z)
		return ((intmax_t)va_arg(*args, ssize_t));
	else
		return ((intmax_t)va_arg(*args, signed int));
}

void			print_decimal(va_list *args, t_info *info)
{
	t_size		*size;
	intmax_t	nbr;

	if (info->format_id == 'D')
		nbr = va_arg(*args, signed long int);
	else
		nbr = signed_modifiers(args, info->modifier);
	set_digit_size(&size, nbr, info);
	digit_precision(size, info);
	number_filler(size, info);
	info->chars_printed += size->size;
	leftjus(info, size);
	free_struct(&size);
}
