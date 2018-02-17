/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:54:17 by ttran             #+#    #+#             */
/*   Updated: 2018/02/16 16:54:18 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		filler(t_size *size, t_info *info)
{
	char	c;
	int		i;
	int		fillsize;

	i = 0;
	c = (info->zero == 1) ? '0' : ' ';
	if (info->width > size->size)
	{
		fillsize = info->width - size->size;
		size->fill = malloc(sizeof(char) * (fillsize + 1));
		size->fill[fillsize] = '\0';
		while (i < fillsize)
			size->fill[i++] = c;
		info->chars_printed += fillsize;
	}
}

char		*wfiller(t_info *info, int strlen)
{
	char	c;
	int		i;
	int		fillsize;
	char	*filler;

	i = 0;
	c = (info->zero == 1) ? '0' : ' ';
	if (info->width > strlen)
	{
		fillsize = info->width - strlen;
		filler = malloc(sizeof(char) * (fillsize + 1));
		filler[fillsize] = '\0';
		while (i < fillsize)
			filler[i++] = c;
		info->chars_printed += fillsize;
		return (filler);
	}
	else
		return (NULL);
}

void		number_filler(t_size *size, t_info *info)
{
	int		fill;

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

static void	unumber_filler_split(t_info *info, int *fill, uintmax_t nbr)
{
	*fill = 0;
	if ((info->format_id == 'o' || info->format_id == 'O') &&
	info->hashtag == 1 && nbr > 0)
		*fill = 1;
	else if (((info->format_id == 'x' || info->format_id == 'X') &&
	info->hashtag == 1 && nbr > 0)
	|| info->format_id == 'p')
		*fill = 2;
}

void		unumber_filler(t_size *size, t_info *info, uintmax_t nbr)
{
	int fill;

	unumber_filler_split(info, &fill, nbr);
	if (info->zero == 0)
	{
		if ((info->hashtag == 1 && nbr > 0) || info->format_id == 'p')
			hashtag_flag(size, info);
		filler(size, info);
	}
	else
	{
		if ((info->width > size->size + fill) && (info->precision == -1
		|| info->format_id == 'p'))
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
