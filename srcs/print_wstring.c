/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 21:43:46 by ttran             #+#    #+#             */
/*   Updated: 2018/02/14 21:43:48 by ttran            ###   ########.fr       */
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
	if (precision >= 0 && *strlen > precision)
	{
		string[precision] = '\0';
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

wchar_t	*nullwstring(void)
{
	wchar_t *null;

	null = malloc(sizeof(wchar_t) * 7);
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	null[6] = '\0';	
	return (null);
}

void	set_wstr_size(wchar_t **string, int *strlen, va_list *args)
{
	*string = ft_wstrdup(va_arg(*args, wchar_t *));
	if (*string == NULL)
		*string = nullwstring();
	*strlen = ft_wstrlen(*string);
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

	fill = NULL;
	set_wstr_size(&string, &strlen, args);
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
	if (fill != NULL)
		free(fill);
}
