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
# include <locale.h>

# define HH 0
# define H 1
# define L 2
# define LL 3
# define J 4
# define Z 5

# define HUNDRED	"\U0001F4AF"
# define BLESS		"\U0001F64F"
# define BLUSH		"\U0001F60A"
# define BOMB		"\U0001F4A3"
# define COFFEE		"\U00002615"
# define CREEP		"\U0001F31D"
# define CRY		"\U0001F622"
# define EXPLODE	"\U0001F4A5"
# define FLEX		"\U0001F4AA"
# define IMP		"\U0001F608"
# define KNIFE		"\U0001F52A"
# define LIT		"\U0001F525"
# define LOL		"\U0001F602"
# define LOVE		"\U0001F60D"
# define MONEY		"\U0001f4B0"
# define OKAY		"\U0001F44C"
# define PARTY		"\U0001F38A"
# define POOP		"\U0001F4A9"
# define RESPEKT	"\U0000270A"
# define SCREAM		"\U0001F631"
# define SWEAT		"\U0001F4A6"
# define SMIRK		"\U0001F60F"
# define SOB		"\U0001F62D"
# define SLEEPY		"\U0001F62A"
# define TADA		"\U0001F389"
# define UMMM		"\U0001F605"
# define WINK		"\U0001F609"
# define WEARY		"\U0001F629"
# define ZZZ		"\U0001F4A4"
# define UNAMUSED	"\U0001F612"

# define BLACK		"\033[0;30m"
# define BLUE		"\033[0;34m"
# define CYAN		"\033[1;36m"
# define DARKYELLOW	"\033[0;33m"
# define EOC		"\033[0m"
# define GREEN		"\033[0;32m"
# define GREY		"\033[1;30m"
# define LAVENDER	"\033[1;35m"
# define LIGHTBLUE	"\033[0;36m"
# define LIGHTGREY	"\033[0;37m"
# define LIME		"\033[1;32m"
# define MAGENTA	"\033[0;35m"
# define PINK		"\033[1;31m"
# define PURPLE		"\033[1;34m"
# define RED		"\033[0;31m"
# define UNDERLINE	"\033[4m"
# define WHITE		"\033[1;37m"
# define YELLOW		"\033[1;33m"

typedef struct		s_info
{
	bool			hashtag;
	bool			zero;
	bool			leftjus;
	bool			plus;
	bool			blank;
	int				width;
	int				precision;
	int				modifier;
	char			format_id;
	int				chars_printed;
}					t_info;

typedef struct		s_size
{
	int				size;
	char			*fill;
	char			*fullchar;
	int				neg;
}					t_size;

typedef struct		s_formatid_struct
{
	char			name;
	void			(*function)(va_list *args, t_info *info);
}					t_formatid_struct;

/*
** Core functions
*/

int					ft_printf(const char *format, ...);
void				nflag(va_list *args, t_info *info);
void				print_invalid_id(t_info *info);
void				print_char(va_list *args, t_info *info);
void				print_string(va_list *args, t_info *info);
void				print_wstring(va_list *args, t_info *info);
void				print_decimal(va_list *args, t_info *info);
void				print_udecimal(va_list *args, t_info *info);

/*
** Struct functions
*/

void				set_info(t_info **info);
void				reset_info(t_info *info);
void				free_struct(t_size **size);

/*
** Dispatch table functions and the initialization
*/

extern				t_formatid_struct g_table[];
void				choose_id(t_info *info, va_list *args);

/*
** Functions for parsing format string into struct
*/

int					format_checker(const char **format, t_info *info,
					va_list *args);
void				width_checker(const char **format, t_info *info,
					va_list *args);
void				precision_checker(const char **format, t_info *info,
					va_list *args);

/*
** Functions to handle the "filler" string for width.
*/

void				filler(t_size *size, t_info *info);
char				*wfiller(t_info *info, int strlen);
void				number_filler(t_size *size, t_info *info);
void				unumber_filler(t_size *size, t_info *info, uintmax_t nbr);

/*
** Functions to handle setting the size of the original input.
*/

void				set_single_size(t_size **size);
void				set_str_size(t_size **size, va_list *args);
void				set_wstr_size(wchar_t **string, int *strlen, va_list *args);
void				set_digit_size(t_size **size, uintmax_t nbr, t_info *info);

/*
** Functions to handle precision
*/

void				wstrprecision(wchar_t *string, int precision, int *strlen);
void				str_precision(t_size *size, t_info *info);
void				digit_precision(t_size *size, t_info *info);

/*
** Various functions to handle wide characters (Crippled)
*/

void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *str);
int					ft_wstrlen(wchar_t *str);
wchar_t				*ft_wstrdup(wchar_t *str);

/*
** Itoa_base versions to deal with converting numbers into a string format.
*/

char				*maxitoa_base(intmax_t value, intmax_t base, t_size *size);
char				*umaxitoa_base(uintmax_t value, uintmax_t base,
					char format_id);

/*
** Functions to handle flags in accordance with width/precision.
*/

void				hashtag_flag(t_size *size, t_info *info);
void				blankplus_flags(t_size *size, t_info *info);
void				leftjus(t_info *info, t_size *size);

/*
** Misc. functions to handle special cases and their helper functions
** I put ft_strduplegit here-- it's just the correct version fo ft_strdup.
** I'll have to edit my libft to fix the old functions I've made in the future.
*/

void				handle_bullshit(t_size *size, t_info *info, int shit);
char				*ft_strcreate(int size, char c);
wchar_t				*nullwstring(void);
char				*nullstring(void);
char				*ft_strduplegit(char *str);

#endif
