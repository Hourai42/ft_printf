# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 14:55:54 by ttran             #+#    #+#              #
#    Updated: 2018/01/21 17:33:18 by ttran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS_DIR = ./srcs/
INCLUDES = ./includes/
RM = /bin/rm -f

FILES = ft_printf format_checker print_char print_invalid_id print_string \
			print_decimal print_udecimal print_wstring nflag
CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))
CFLAGS = -Wall -Wextra -Werror

#libft
LFT = ./libft/
LFT_FILES = ft_putchar ft_strchr ft_putstr ft_strlen ft_strdup ft_strjoin \
				ft_strnew
LFT_CFILES = $(patsubst %, $(LFT)%.c, $(LFT_FILES))
LFT_OFILES = $(patsubst %, %.o, $(LFT_FILES))
LFT_LIB = $(addprefix $(LFT), ft.a)
LFT_INC = -I $(LFT)

all: $(LFT_LIB) $(NAME)

$(LFT_LIB):
	@make -C $(LFT)

$(OFILES):
	@gcc $(CFLAGS) -c -I$(INCLUDES) $(LFT_INC) $(LFT_CFILES) $(CFILES)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES) $(LFT_OFILES)
	@ranlib $(NAME)

clean:
	@make -C $(LFT) clean
	@$(RM) $(OFILES)
	@$(RM) $(LFT_OFILES)

fclean: clean
	@make -C $(LFT) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
