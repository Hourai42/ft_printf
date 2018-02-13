# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:39:27 by ttran             #+#    #+#              #
#    Updated: 2018/01/19 15:32:14 by ttran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAG = -Wall -Wextra -Werror
SRCS_DIR = ./
CC = gcc
FILES = ft_strrchr ft_putstr ft_strcmp ft_strlcat ft_memcpy \
		ft_strequm ft_memmove ft_strsplit ft_strncpy ft_lstmap \
		ft_lstadd ft_striter ft_strstr ft_isdigit ft_putnbr \
		ft_memccpy ft_strdel ft_nmbwrd ft_memchr ft_bzero \
		ft_isalnum ft_putstr_fd ft_lstiter ft_lstdelone ft_toupper \
		ft_strcpy ft_lstnew ft_strdup ft_putnbr_fd ft_striteri \
		ft_strmap ft_putendl_fd ft_memdel ft_strnstr ft_putchar \
		ft_isascii ft_strlen ft_strsub ft_strnew ft_memalloc ft_putendl \
		ft_strncat ft_itoa ft_strncmp ft_memcmp ft_strtrim ft_strequ \
		ft_putchar_fd ft_memset ft_isalpha ft_strcat ft_tolower \
		ft_strnequ ft_strjoin ft_atoi ft_strclr ft_strmapi \
		ft_isprint ft_lstdel ft_strchr ft_mallocwrd ft_countplace \
		ft_isprime ft_hassqrt ft_fibonacci ft_recursive_power \
		ft_recursive_factorial get_next_line

RM = @/bin/rm -f 

CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))

all: $(NAME)

$(NAME): $(OFILES)
		@ar rc $(NAME) $(OFILES)
		@ranlib $(NAME)

$(OFILES):
		@$(CC) $(CFLAGS) -c $(CFILES)

clean:
		@$(RM) $(OFILES)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re