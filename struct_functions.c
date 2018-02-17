/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:42:51 by ttran             #+#    #+#             */
/*   Updated: 2018/02/16 16:42:56 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	free_struct(t_size **size)
{
	if ((*size)->fill != NULL)
		free((*size)->fill);
	if ((*size)->fullchar != NULL)
		free((*size)->fullchar);
	free(*size);
}
