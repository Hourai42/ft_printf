/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:56:44 by ttran             #+#    #+#             */
/*   Updated: 2018/02/16 16:56:53 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_single_size(t_size **size)
{
	*size = malloc(sizeof(t_size));
	(*size)->size = 1;
	(*size)->fill = NULL;
	(*size)->fullchar = NULL;
}

void	set_str_size(t_size **size, va_list *args)
{
	*size = malloc(sizeof(t_size));
	(*size)->fullchar = ft_strduplegit(va_arg(*args, char *));
	(*size)->fill = NULL;
	if ((*size)->fullchar == NULL)
		(*size)->fullchar = nullstring();
	(*size)->size = ft_strlen((*size)->fullchar);
}

void	set_wstr_size(wchar_t **string, int *strlen, va_list *args)
{
	*string = ft_wstrdup(va_arg(*args, wchar_t *));
	if (*string == NULL)
		*string = nullwstring();
	*strlen = ft_wstrlen(*string);
}

void	set_digit_size(t_size **size, uintmax_t nbr, t_info *info)
{
	*size = malloc(sizeof(t_size));
	(*size)->neg = 1;
	if ((info->precision == 0 || info->precision == -2) && nbr == 0)
	{
		if ((info->format_id == 'o' || info->format_id == 'O')
		&& info->hashtag == 1)
			(*size)->fullchar = ft_strcreate(1, '0');
		else
			(*size)->fullchar = ft_strnew(0);
	}
	else if (info->format_id == 'd' || info->format_id == 'i'
	|| info->format_id == 'D')
		(*size)->fullchar = maxitoa_base(nbr, 10, *size);
	else if (info->format_id == 'o' || info->format_id == 'O')
		(*size)->fullchar = umaxitoa_base(nbr, 8, info->format_id);
	else if (info->format_id == 'u' || info->format_id == 'U')
		(*size)->fullchar = umaxitoa_base(nbr, 10, info->format_id);
	else
		(*size)->fullchar = umaxitoa_base(nbr, 16, info->format_id);
	(*size)->size = ft_strlen((*size)->fullchar);
	(*size)->fill = NULL;
}
