/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:06:44 by ttran             #+#    #+#             */
/*   Updated: 2018/02/12 14:06:45 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Interesting. It's nice how consistent everything is-- the syntax for setting
** an array of ints/chars is the same as structs. 
*/

t_formatid_struct g_table[] =
{
	{'c', print_char},
	{'C', print_char},
	{'s', print_string},
	{'S', print_string},
	{'d', print_decimal},
	{'D', print_decimal},
	{'i', print_decimal},
	{'u', print_udecimal},
	{'U', print_udecimal},
	{'o', print_udecimal},
	{'O', print_udecimal},
	{'x', print_udecimal},
	{'X', print_udecimal},
	{'p', print_udecimal}
};

/*
** For precision, -1 is "no precision" and -2 is "no number specified".
** For width, it's simply 0. 
*/

void	set_info(t_info **info)
{
	*info = malloc(sizeof(t_info));
	(*info)->hashtag = 0;
	(*info)->zero = 0;
	(*info)->leftjus = 0;
	(*info)->plus = 0;
	(*info)->blank = 0;
	(*info)->width = 0;
	(*info)->precision = -1;
	(*info)->modifier = -1;
	(*info)->format_id = 0;
	(*info)->chars_printed = 0;
}

void	reset_info(t_info *info)
{
	info->hashtag = 0;
	info->zero = 0;
	info->leftjus = 0;
	info->plus = 0;
	info->blank = 0;
	info->width = 0;
	info->precision = -1;
	info->modifier = -1;
	info->format_id = 0;
}

void	choose_id(t_info *info, va_list *args)
{
	int i;

	i = 0;
	while (info->format_id != (g_table[i]).name)
		i++;
	g_table[i].function(args, info);
}

/*
** Prints format string untl it encounters a '%', which will make it print the next variadic function argument in line.
*/

int ft_printf(const char *format, ...)
{/*
	va_list args;
	t_info *info;
	int chars;

	set_info(&info);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			format_checker(&format, info, &args);
		else
		{
			ft_putchar(*format);
			info->chars_printed++;
			format++;
		}
	}
	va_end(args);
	chars = info->chars_printed;
	free(info);
	return (chars); */ft_putstr(format);
	return (0);
}
