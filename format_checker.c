/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:53:28 by ttran             #+#    #+#             */
/*   Updated: 2018/02/12 14:53:29 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Format kept at 0 if no proper format_id is provided. It doesn't move the
** pointer forward and simply prints the character.
*/

static int	formatid_checker(const char **format, t_info *info)
{
	char	*str;

	str = "nsSpdiDoOuUxXcC";
	if (**format == '\0')
		return (0);
	else if (ft_strchr(str, **format) == NULL)
	{
		info->format_id = **format;
		(*format)++;
		print_invalid_id(info);
		return (0);
	}
	else
	{
		info->format_id = **format;
		(*format)++;
	}
	return (1);
}

static void	modifier_checker(const char **format, t_info *info)
{
	if (**format == 'h' || **format == 'l' || **format == 'j'
	|| **format == 'z')
	{
		if (**format == 'h' && *((*format) + 1) == 'h')
			info->modifier = 0;
		else if (**format == 'l' && *((*format) + 1) == 'l')
			info->modifier = 3;
		else
		{
			if (**format == 'h')
				info->modifier = 1;
			else if (**format == 'l')
				info->modifier = 2;
			else if (**format == 'j')
				info->modifier = 4;
			else if (**format == 'z')
				info->modifier = 5;
		}
		(*format)++;
	}
	if (info->modifier == 0 || info->modifier == 3)
		(*format)++;
	while (**format == 'h' || **format == 'l' || **format == 'j'
	|| **format == 'z')
		(*format)++;
}

/*
** Deals with conflicting flags by setting them back to zero and
** reiterates through multiple flags.
*/

static void	flag_checker(const char **format, t_info *info)
{
	while (**format && (**format == ' ' || **format == '#' || **format == '0'
	|| **format == '-' || **format == '+'))
	{
		if (**format == ' ')
			info->blank = 1;
		else if (**format == '#')
			info->hashtag = 1;
		else if (**format == '0')
			info->zero = 1;
		else if (**format == '-')
			info->leftjus = 1;
		else if (**format == '+')
			info->plus = 1;
		(*format)++;
	}
	if (info->leftjus == 1 && info->zero == 1)
		info->zero = 0;
	if (info->plus == 1 && info->blank == 1)
		info->blank = 0;
}

static void	handle_percent(const char **format, t_info *info)
{
	ft_putchar('%');
	info->chars_printed++;
	(*format)++;
}

/*
** Parses all information into struct.
*/

int			format_checker(const char **format, t_info *info, va_list *args)
{
	(*format)++;
	if (**format == '%')
		handle_percent(format, info);
	else
	{
		flag_checker(format, info);
		width_checker(format, info, args);
		precision_checker(format, info, args);
		modifier_checker(format, info);
		if (formatid_checker(format, info) == 1)
			choose_id(info, args);
		reset_info(info);
	}
	return (1);
}
