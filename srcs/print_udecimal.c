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

int		umaxcount_digits(uintmax_t value, uintmax_t base)
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
#include <stdio.h>
char	*umaxitoa_base(uintmax_t value, uintmax_t base, char format_id)
{
	int digits;
	char *nbr;
	char a;

	if (format_id == 'X')
		a = 'A';
	else
		a = 'a';
	digits = umaxcount_digits(value, base);
	nbr = malloc(sizeof(char) * (digits + 1));
	nbr[digits--] = '\0';
	while (digits >= 0)
	{
		nbr[digits--] = (value % base > 9) ? value % base - 10 + a: value % base + '0';
		value /= base;
	}
	return (nbr);
}

uintmax_t    unsigned_modifiers(va_list *args, int modifier)
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

char    *sext(char format_id)
{
	char *notsex;

	notsex = malloc(sizeof(char) * 3);
	notsex[2] = '\0';
	notsex[0] = '0';
	if (format_id == 'x' || format_id == 'p')
		notsex[1] = 'x';
	else
		notsex[1] = 'X';
	return (notsex);
}

void    hashtag_flag(t_size *size, t_info *info)
{
	char *pasflag;
	char *flaggednbr;

	if (info->format_id == 'o' || info->format_id == 'O')
	{
		pasflag = ft_strcreate(1, '0');
		flaggednbr = ft_strjoin(pasflag, size->fullchar);
		free(pasflag);
		free(size->fullchar);
		size->fullchar = flaggednbr;
		size->size++;
	}
	else if (info->format_id == 'x' || info->format_id == 'X' || info->format_id == 'p')
	{
		pasflag = sext(info->format_id);
		flaggednbr = ft_strjoin(pasflag, size->fullchar);
		free(pasflag);
		free(size->fullchar);
		size->fullchar = flaggednbr;
		size->size += 2;
	} 
}

void	unumber_filler(t_size *size, t_info *info, uintmax_t nbr)
{
	int fill;

	fill = 0;
	if ((info->format_id == 'o' || info->format_id == 'O') && info->hashtag == 1 && nbr > 0) 
		fill = 1;
	else if (((info->format_id == 'x' || info->format_id == 'X') && info->hashtag == 1 && nbr > 0)
	|| info->format_id == 'p')
		fill = 2;
	if (info->zero == 0)
	{
		if ((info->hashtag == 1 && nbr > 0) || info->format_id == 'p')
			hashtag_flag(size, info);
		filler(size, info);
	}
	else
	{
		if ((info->width > size->size + fill) && (info->precision == -1 || info->format_id == 'p'))
			handle_bullshit(size, info, fill);
		else if ((info->hashtag == 1 && nbr > 0) || info->format_id == 'p')
			hashtag_flag(size, info);
		if (info->width > size->size)
		{
			info->zero = 0;
			filler(size, info);
		}
	}
}

/*
** Just about everything unsigned ignores the "plus" or "blank" flags.
*/

void    print_udecimal(va_list *args, t_info *info)
{
	t_size *size;
	uintmax_t nbr;
	
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
