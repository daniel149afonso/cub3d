/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:32:43 by scuthber          #+#    #+#             */
/*   Updated: 2024/10/09 15:21:45 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Part 1
int		ft_isalpha(int c);
int		ft_isdigit(int n);
int		ft_isalnum(int n);
int		ft_isascii(int n);
int		ft_isprint(int n);
size_t	ft_strlen(const char	*str);
void	*ft_memset(void	*str, int c, size_t n);
void	ft_bzero(void	*str, size_t n);
void	*ft_memcpy(void	*dst, const void *src, size_t n);
void	*ft_memmove(void	*dst, const void *src, size_t n);
size_t	ft_strlcpy(char	*dst, const char *src, size_t size);
size_t	ft_strlcat(char	*dst, char	*src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char	*s, int c);
char	*ft_strrchr(const char	*s, int c);
int		ft_strncmp(const char	*s1, const char	*s2, size_t n);
void	*ft_memchr(const void	*s, int c, size_t n);
int		ft_memcmp(const void	*s1, const void	*s2, size_t n);
char	*ft_strnstr(const char	*haystack, const char	*needle,
			size_t len);
int		ft_atoi(const char	*str);
void	*ft_calloc(size_t count, size_t size);

// Part 2
char	*ft_strdup(const char	*s);
char	*ft_substr(const char	*s, size_t start, size_t len);
char	*ft_strjoin(const char	*s1, const char	*s2);
char	*ft_strtrim(const char	*s1, const char	*set);
char	**ft_split(const char	*s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char	*s, char (*f)(unsigned int, char));
void	ft_striteri(char	*s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char	*s, int fd);
void	ft_putendl_fd(char	*s, int fd);
void	ft_putnbr_fd(int n, int fd);

// othervoid
void	*ft_realloc(void	*ptr, size_t old_size, size_t new_size);

// bonus
t_list	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_list	**lst, t_list	*new);
int		ft_lstsize(t_list	*lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list	**lst, t_list	*new);
void	ft_lstdelone(t_list	*lst, void (*del)(void *));
void	ft_lstclear(t_list	**lst, void (*del)(void *));
void	ft_lstiter(t_list	*lst, void (*f)(void *));
t_list	*ft_lstmap(t_list	*lst, void	*(*f)(void *), void (*del)(void *));

// printf
int		ft_printf(const char	*str, ...);
void	ft_putnbr_u(unsigned int n, int fd);
int		ft_print_hex(unsigned long nb, int upcase);
int		ft_count_nb(int nb);
int		ft_count_u_nb(unsigned int nb);
int		ft_print_c(va_list args);
int		ft_print_s(va_list args);
int		ft_print_i(va_list args);
int		ft_print_u(va_list args);
int		ft_print_p(va_list args);
int		ft_print_x(va_list args, int uppercase);

// Get next line
char	*get_next_line(int fd);
#endif