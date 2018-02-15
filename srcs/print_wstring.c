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

void	ft_putwchar(wchar_t c)
{
	write(1, &c, 1);
}

void    print_wstring(va_list *args, t_info *info)
{
	wchar_t *string;

	info = 0;
	string = va_arg(*args, wchar_t *);
	while (*string)
	{
		ft_putwchar(*string);
		string++;
	}
}
