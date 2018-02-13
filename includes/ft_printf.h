/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:06:23 by ttran             #+#    #+#             */
/*   Updated: 2018/02/12 14:06:24 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <libft.h>
# include <stdint.h> 

# define HH 0
# define H 1
# define L 2
# define LL 3
# define J 4
# define Z 5

typedef struct s_info
{
	bool hashtag;
	bool zero;
	bool leftjus;
	bool plus;
	bool blank;
	int width;
	int precision;
	int modifier;
	char format_id;
	int chars_printed;
}               t_info;

typedef struct s_size
{
	int size;
	char *fill;
	char *fullchar;
}               t_size;

typedef struct  s_formatid_struct
{
	char    name;
	void    (*function)(va_list *args, t_info *info);
}               t_formatid_struct;

extern t_formatid_struct g_table[];

int ft_printf(const char *format, ...);
int		format_checker(const char **format, t_info *info, va_list *args);
void	reset_info(t_info *info);
void	print_invalid_id(t_info *info);
void	choose_id(t_info *info, va_list *args);
void    set_single_size(t_size **size);
void    free_struct(t_size **size);
void    filler(t_size *size, t_info *info);

void    print_char(va_list *args, t_info *info);
void    print_string(va_list *args, t_info *info);
void    print_decimal(va_list *args, t_info *info);

#endif
