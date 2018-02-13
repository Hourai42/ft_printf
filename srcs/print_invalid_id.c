/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:42:50 by ttran             #+#    #+#             */
/*   Updated: 2018/02/12 18:42:51 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    set_single_size(t_size **size)
{
    *size = malloc(sizeof(t_size));
    (*size)->size = 1;
    (*size)->fill = NULL;
    (*size)->fullchar = NULL;
}

void    free_struct(t_size **size)
{
    if ((*size)->fill != NULL)
        free((*size)->fill);
    if ((*size)->fullchar != NULL)
        free((*size)->fullchar);
    free(*size);
}

void    filler(t_size *size, t_info *info)
{
    char c;
    int i;
    int fillsize;

    i = 0;
    c = (info->zero == 1) ? '0' : ' ';
    if (info->width > size->size)
    {
        fillsize = info->width - size->size;    
        size->fill = malloc(sizeof(char) * (fillsize + 1));
        size->fill[fillsize] = '\0';
        while (i < fillsize)
            size->fill[i++] = c; 
        info->chars_printed += fillsize;
    }
}
/*
** A trial for the real "print" function. Create a struct to handle width/precision and such.
*/

void	print_invalid_id(t_info *info)
{
    t_size *size;

    set_single_size(&size);
    filler(size, info);
    info->chars_printed += size->size;
    if (info->leftjus == 1)
    {
        ft_putchar(info->format_id);
        ft_putstr(size->fill);
    }
    else
    {
        ft_putstr(size->fill);
        ft_putchar(info->format_id);
    }
    free_struct(&size);
}
