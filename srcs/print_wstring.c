/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 21:43:46 by ttran             #+#    #+#             */
/*   Updated: 2018/02/15 19:29:30 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** An intentionally crippled version of ft_putwchar. 
*/

void	ft_putwchar(wchar_t c)
{
	write(1, &c, 1);
}

void	ft_putwstr(wchar_t *str)
{
	while (*str)
	{
		ft_putwchar(*str);
		str++;
	}
}

int		ft_wstrlen(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
** An intentionally crippled version of wstrprecision.
*/

void	wstrprecision(wchar_t *string, int precision, int *strlen)
{
	int i;

	i = 0;
	if (precision == -2)
		precision = 0;
	else if (precision >= 0)
	{
		while (string[i] && i < precision)
			i++;
		string[i] = '\0';
		*strlen = ft_wstrlen(string);
	}
}

wchar_t *ft_wstrdup(wchar_t *str)
{
	int i;
	wchar_t *s2;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	s2 = malloc(sizeof(wchar_t) * (i + 1));
	i = 0;
	while (str[i])
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int		set_wstr_size(wchar_t **string, int *strlen, va_list *args, t_info *info)
{
	*string = ft_wstrdup(va_arg(*args, wchar_t *));
	if (*string == NULL)
	{
		ft_putstr("(null)");
		info->chars_printed += 6;
		return (1);
	}
	*strlen = ft_wstrlen(*string);
	return (0);
}

char	*wfiller(t_info *info, int strlen)
{
	char c;
	int i;
	int fillsize;
	char *filler;

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

void    print_wstring(va_list *args, t_info *info)
{
	wchar_t *string;
	int strlen;
	char *fill;

	if (1)
		ft_putstr("fuck you\n");
	else
	{
		fill = NULL;
		if (set_wstr_size(&string, &strlen, args, info) == 0)
		{
			wstrprecision(string, info->precision, &strlen);
			fill = wfiller(info, strlen);
			info->chars_printed += strlen;
			if (info->leftjus == 1)
			{
				ft_putwstr(string);
				ft_putstr(fill);
			}
			else
			{
				ft_putstr(fill);
				ft_putwstr(string);
			}
			free(string);
		}
		if (fill != NULL)
			free(fill);
	}
}
