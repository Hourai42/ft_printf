/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:15:13 by ttran             #+#    #+#             */
/*   Updated: 2018/02/16 17:15:21 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** An intentionally crippled version of wstrprecision.
*/

void		wstrprecision(wchar_t *string, int precision, int *strlen)
{
	int		i;

	i = 0;
	if (precision == -2)
		precision = 0;
	if (precision >= 0 && *strlen > precision)
	{
		string[precision] = '\0';
		*strlen = ft_wstrlen(string);
	}
}

static void	truncate_string(t_size *size, int max)
{
	char	*truncatedstr;
	int		i;

	i = 0;
	truncatedstr = malloc(sizeof(char) * (max + 1));
	while (i < max)
	{
		truncatedstr[i] = size->fullchar[i];
		i++;
	}
	truncatedstr[i] = '\0';
	free(size->fullchar);
	size->fullchar = truncatedstr;
	size->size = max;
}

void		str_precision(t_size *size, t_info *info)
{
	if (info->precision == -2)
		info->precision = 0;
	if (info->precision >= 0 && (size->size > info->precision))
		truncate_string(size, info->precision);
}

static void	pad_digit(t_size *size, int pad)
{
	char	*minpad;
	char	*paddednbr;

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

void		digit_precision(t_size *size, t_info *info)
{
	if (info->precision == -2)
		info->precision = 0;
	if (info->precision >= 0 && (info->precision > size->size))
	{
		if ((info->format_id == 'o' || info->format_id == 'O')
		&& info->hashtag == 1)
			info->hashtag = 0;
		pad_digit(size, info->precision - size->size);
	}
}
