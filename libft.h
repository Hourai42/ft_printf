/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:58:31 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 19:30:26 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 80
# define FD_LIMIT 9001
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int					get_next_line(const int fd, char **line);
int					gtfoline(char **holder, char **line);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(char *str);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *big, const char *little);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strncat(char *restrict s1,
					const char *restrict s2, size_t n);
char				*ft_strnstr(const char *big,
					const char *little, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *restrict dst,
					const void *restrict src, size_t n);
void				*ft_memccpy(void *restrict dst,
					const void *restrict src, int c,
					size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *restrict dst,
					const char *restrict src, size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *s));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_strequm(char const *big, char const *small);
int					ft_nmbwrd(char *str, char c);
char				*ft_mallocwrd(char *str, int spot, char c);
int					ft_countplace(int n);
int					ft_recursive_factorial(int nb);
int					ft_recursive_power(int nb, int power);
int					ft_fibonacci(int index);
int					ft_hassqrt(int nb);
int					ft_isprime(int n);
#endif
