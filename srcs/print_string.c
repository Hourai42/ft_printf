/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 21:41:25 by ttran             #+#    #+#             */
/*   Updated: 2018/02/15 23:55:36 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    truncate_string(t_size *size, int max)
{
	char *truncatedstr;
	int i;

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

void    str_precision(t_size *size, t_info *info)
{
	if (info->precision == -2)
		info->precision = 0;
	if (info->precision >= 0 && (size->size > info->precision))
		truncate_string(size, info->precision);
}

char	*nullstring(void)
{
	char *null;

	null = malloc(sizeof(char) * 7);
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	null[6] = '\0';	
	return (null);
}

char	*ft_strduplegit(char *str)
{
	int		i;
	char	*s2;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\0')
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

#include <stdio.h>
void	set_str_size(t_size **size, va_list *args, t_info *info)
{
	wchar_t *fucker;

	*size = malloc(sizeof(t_size));
	if (info->format_id == 'S' || info->modifier == L)
	{
		fucker = va_arg(*args, wchar_t *);
		//printf("%S\n", fucker);
		//ft_putstr((char *)fucker);
		//ft_putchar('\n');
		//(*size)->fullchar = ft_strduplegit((char *)(va_arg(*args, wchar_t *)));
		(*size)->fullchar = ft_strduplegit((char *)fucker);
	}
	else
		(*size)->fullchar = ft_strduplegit(va_arg(*args, char *));
	(*size)->fill = NULL;
	if ((*size)->fullchar == NULL)
		(*size)->fullchar = nullstring();
	(*size)->size = ft_strlen((*size)->fullchar);
}

void    print_string(va_list *args, t_info *info)
{
	t_size *size;

	set_str_size(&size, args, info);
	str_precision(size, info);
	filler(size, info);		
	info->chars_printed += size->size;
	if (info->leftjus == 1)
	{
		ft_putstr(size->fullchar);
		ft_putstr(size->fill);
	}
	else
	{
		ft_putstr(size->fill);
		ft_putstr(size->fullchar);
	}
	free_struct(&size);
}
