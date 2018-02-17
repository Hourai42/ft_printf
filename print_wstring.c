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

wchar_t		*nullwstring(void)
{
	wchar_t	*null;

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

void		print_wstring(va_list *args, t_info *info)
{
	wchar_t	*string;
	int		strlen;
	char	*fill;

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
