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
	nbr = malloc(sizeof(char) * digits);
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
		return ((uintmax_t)va_arg(*args, unsigned long int));
}

char    *sex(char xX)
{
    char *sex;

    sex = malloc(sizeof(char) * 3);
    sex[2] = '\0';
    sex[0] = '0';
    sex[1] = xX;
    return (sex);
}

void    hashtag_flag(t_size *size, t_info *info)
{
    char *posflag;
    char *flaggednbr;

    if (info->format_id == 'o' || info->format_id == 'O')
    {
        posflag = ft_strcreate(1, '0');
        flaggednbr = ft_strjoin(posflag, size->fullchar);
        free(posflag);
        free(size->fullchar);
        size->fullchar = flaggednbr;
        size->size++;
    }
    else if (info->format_id == 'x' || info->format_id == 'X' || info->format_id == 'p')
    {
        posflag = sex(info->format_id);
        flaggednbr = ft_strjoin(posflag, size->fullchar);
        free(posflag);
        free(size->fullchar);
        size->fullchar = flaggednbr;
        size->size += 2;
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
    else
        nbr = unsigned_modifiers(args, info->modifier);
    set_digit_size(&size, nbr, info);
    digit_precision(size, info);
    if ((info->hashtag == 1 && nbr > 0) || info->format_id == 'p')
        hashtag_flag(size, info);
    filler(size, info);
    info->chars_printed += size->size;
    leftjus(info, size);
    free_struct(&size);
}
