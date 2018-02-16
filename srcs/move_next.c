/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 00:59:12 by ttran             #+#    #+#             */
/*   Updated: 2018/02/16 00:59:13 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
void    move_next(va_list *args, t_info *info)
{
    int fuck;
    int you;

    fuck = va_arg(*args, int);
    printf("%d", fuck);
    you = (int)info->format_id;
}