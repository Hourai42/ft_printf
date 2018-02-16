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
# include <wchar.h>

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
	bool nflag;
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
	int neg;
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
char	*ft_strcreate(int size, char c);
void	set_digit_size(t_size **size, uintmax_t nbr, t_info *info);
void	leftjus(t_info *info, t_size *size);
void	digit_precision(t_size *size, t_info *info);
char	*umaxitoa_base(uintmax_t value, uintmax_t base, char format_id);
int		umaxcount_digits(uintmax_t value, uintmax_t base);
void    print_char(va_list *args, t_info *info);
void    print_string(va_list *args, t_info *info);
void    print_decimal(va_list *args, t_info *info);
void    print_udecimal(va_list *args, t_info *info);
void	handle_bullshit(t_size *size, t_info *info, int shit);
void    print_wstring(va_list *args, t_info *info);
void    move_next(va_list *args, t_info *info);
void	ft_putwstr(wchar_t *str);

#endif
