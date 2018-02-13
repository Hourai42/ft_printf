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

int		maxcount_digits(intmax_t value, intmax_t base)
{
	int count;

	count = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= base;
		count++;
	}
	return (count);
}

/*
** Interesting. There are diff. definitions of intmax_t(long long) min because 
** it's a unary operator applied to the constant 9223372036854775808LL. 
** You have to edit the limits or stdint header file if you want to make
** a valid min value compile for intmax_t. "#define MIN_INT (-MAX_INT - 1)"
*/

char	*maxitoa_base(intmax_t value, intmax_t base)
{
	int neg;
	int digits;
	char *nbr;

	neg = 0;
	digits = maxcount_digits(value, base);
	if (value < 0)
	{
		neg = 1;
		value *= -1;
	}
	digits += neg;
	nbr = malloc(sizeof(char) * digits);
	nbr[digits--] = '\0';
	while (digits >= neg)
	{
		nbr[digits--] = (value % base > 9) ? value % base - 10 + 'A': value % base + '0';
		value /= base;
	}
	if (neg == 1)
		nbr[0] = '-';
	return (nbr);
}

intmax_t    signed_modifiers(va_list *args, int modifier)
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

char	*ft_strcreate(int size, char c)
{
	char *str;
	int i;

	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (NULL);
	while (i < size)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

void	pad_digit(t_size *size, int pad)
{
	char *minpad;
	char *paddednbr;

	minpad = ft_strcreate(pad, '0');
	paddednbr = ft_strjoin(minpad, size->fullchar);
	free(minpad);
	free(size->fullchar);
	size->fullchar = paddednbr;
	size->size += pad;
}

/*
** The size of the padding is the min. number of digits - the current size.
*/

void	digit_precision(t_size *size, t_info *info)
{
	if (info->precision == -2)
		info->precision = 0;
	if (info->precision >= 0 && (info->precision > size->size))
		pad_digit(size, info->precision - size->size);
}

void	set_digit_size(t_size **size, int nbr, t_info *info)
{
	*size = malloc(sizeof(t_size));
	if (info->format_id == 'd' || info->format_id == 'i' || info->format_id == 'u')
		(*size)->fullchar = maxitoa_base(nbr, 10);
	else if (info->format_id == 'o' || info->format_id == 'O')
		(*size)->fullchar = maxitoa_base(nbr, 8);
	else
		(*size)->fullchar = maxitoa_base(nbr, 16);
	(*size)->size = ft_strlen((*size)->fullchar);
	(*size)->fill = NULL;
}

void	di_flags(t_size *size, t_info *info)
{
	char *posflag;
	char *flaggednbr;

	posflag = ft_strcreate(1, (info->blank == 1) ? ' ' : '+');
	flaggednbr = ft_strjoin(posflag, size->fullchar);
	free(posflag);
	free(size->fullchar);
	size->fullchar = flaggednbr;
	size->size++;
}

void    print_decimal(va_list *args, t_info *info)
{
	t_size *size;
	intmax_t nbr;

	nbr = signed_modifiers(args, info->modifier);
	set_digit_size(&size, nbr, info);
	digit_precision(size, info);
	if (nbr > 0 && (info->blank == 1 || info->plus == 1))
		di_flags(size, info);
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
