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
/*
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
*/

/*
** A modified maxitoa_base that never prints negatives, but is made aware of it. Treat negative as a flag! 
*/

char	*maxitoa_base(intmax_t value, intmax_t base, t_size *size)
{
	int digits;
	char *nbr;

	digits = maxcount_digits(value, base);
	if (value < 0)
		size->neg *= -1;
	nbr = malloc(sizeof(char) * (digits + 1));
	nbr[digits--] = '\0';
	while (digits >= 0)
	{
		nbr[digits--] = ((value % base * size->neg) > 9) ?
		(value % base * size->neg) - 10 + 'A': (value % base * size->neg) + '0';
		value /= base;
	}
	return (nbr);
}

/*
** The reason for returning as a signed long instead of a signed int is to
** handle DOU. 
*/

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
	{
		if ((info->format_id == 'o' || info->format_id == 'O') && info->hashtag == 1)
			info->hashtag = 0;
		pad_digit(size, info->precision - size->size);
	}
}

void	set_digit_size(t_size **size, uintmax_t nbr, t_info *info)
{
	*size = malloc(sizeof(t_size));
	(*size)->neg = 1;
	if ((info->precision == 0 || info->precision == -2) && nbr == 0)
	{
		if ((info->format_id == 'o' || info->format_id == 'O') && info->hashtag == 1)
			(*size)->fullchar = ft_strcreate(1, '0');
		else
			(*size)->fullchar = ft_strnew(0);
	}
	else if (info->format_id == 'd' || info->format_id == 'i' || info->format_id == 'D')
		(*size)->fullchar = maxitoa_base(nbr, 10, *size);
	else if (info->format_id == 'o' || info->format_id == 'O')
		(*size)->fullchar = umaxitoa_base(nbr, 8, info->format_id);
	else if (info->format_id == 'u' || info->format_id == 'U')
		(*size)->fullchar = umaxitoa_base(nbr, 10, info->format_id);
	else
		(*size)->fullchar = umaxitoa_base(nbr, 16, info->format_id);
	(*size)->size = ft_strlen((*size)->fullchar);
	(*size)->fill = NULL;
}

void	blankplus_flags(t_size *size, t_info *info)
{
	char *posflag;
	char *flaggednbr;
	char c;

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

void	leftjus(t_info *info, t_size *size)
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

void	handle_single(t_size *size, t_info *info)
{
		if (size->neg == -1)
			size->fullchar[0] = '-';
		else if (info->plus == 1)
			size->fullchar[0] = '+';
		else
			size->fullchar[0] = ' ';
}

void	handle_bullshit(t_size *size, t_info *info, int shit)
{
	char *shitty;
	char *paddednbr;

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

void	number_filler(t_size *size, t_info *info)
{
	int fill;

	fill = 0;
	if (info->blank == 1 || info->plus == 1 || size->neg == -1)
		fill = 1;
	if (info->zero == 0)
	{
		if (info->blank == 1 || info->plus == 1 || size->neg == -1)
			blankplus_flags(size, info);
		filler(size, info);
	}
	else
	{
		if ((info->width > size->size + fill) && info->precision == -1)
			handle_bullshit(size, info, fill);
		else if (info->blank == 1 || info->plus == 1 || size->neg == -1)
			blankplus_flags(size, info);
		if (info->width > size->size)
		{
			info->zero = 0;
			filler(size, info);
		}
	}
}

void    print_decimal(va_list *args, t_info *info)
{
	t_size *size;
	intmax_t nbr;

	if (info->nflag == 1)
	{
		nbr = info->chars_printed;
		info->nflag = 0;
	}
	else if (info->format_id == 'D')
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
