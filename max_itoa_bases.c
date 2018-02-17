/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_itoa_bases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:21:57 by ttran             #+#    #+#             */
/*   Updated: 2018/02/16 17:22:04 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	maxcount_digits(intmax_t value, intmax_t base)
{
	int		count;

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
** A modified maxitoa_base that never prints negatives, but is made aware of it.
** Treat negative as a flag!
** Interesting. There are diff. definitions of intmax_t(long long) min because
** it's a unary operator applied to the constant 9223372036854775808LL.
** You have to edit the limits or stdint header file if you want to make
** a valid min value compile for intmax_t. "#define MIN_INT (-MAX_INT - 1)"
*/

char		*maxitoa_base(intmax_t value, intmax_t base, t_size *size)
{
	int		digits;
	char	*nbr;

	digits = maxcount_digits(value, base);
	if (value < 0)
		size->neg *= -1;
	nbr = malloc(sizeof(char) * (digits + 1));
	nbr[digits--] = '\0';
	while (digits >= 0)
	{
		nbr[digits--] = ((value % base * size->neg) > 9) ?
		(value % base * size->neg) - 10 + 'A' : (value % base * size->neg)
		+ '0';
		value /= base;
	}
	return (nbr);
}

static int	umaxcount_digits(uintmax_t value, uintmax_t base)
{
	int		count;

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

char		*umaxitoa_base(uintmax_t value, uintmax_t base, char format_id)
{
	int		digits;
	char	*nbr;
	char	a;

	if (format_id == 'X')
		a = 'A';
	else
		a = 'a';
	digits = umaxcount_digits(value, base);
	nbr = malloc(sizeof(char) * (digits + 1));
	nbr[digits--] = '\0';
	while (digits >= 0)
	{
		nbr[digits--] = (value % base > 9) ?
		value % base - 10 + a : value % base + '0';
		value /= base;
	}
	return (nbr);
}
