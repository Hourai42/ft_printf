/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:49:40 by ttran             #+#    #+#             */
/*   Updated: 2018/02/16 16:49:41 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_checker(const char **format, t_info *info, va_list *args)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			info->precision = va_arg(*args, int);
			if (info->precision < 0)
				info->precision = -1;
			(*format)++;
		}
		else if (**format >= '0' && **format <= '9')
		{
			info->precision = 0;
			while (**format >= '0' && **format <= '9')
				info->precision = info->precision * 10 + (*(*format)++ - '0');
		}
		else
			info->precision = -2;
	}
}

void	width_checker(const char **format, t_info *info, va_list *args)
{
	int i;

	while (**format == '*' || (**format >= '0' && **format <= '9'))
	{
		i = 0;
		if (**format == '*')
		{
			i = va_arg(*args, int);
			if (i < 0)
			{
				i *= -1;
				info->leftjus = 1;
				info->zero = 0;
			}
			(*format)++;
		}
		else
			while (**format >= '0' && **format <= '9')
				i = i * 10 + (*(*format)++ - '0');
		info->width = i;
	}
}
