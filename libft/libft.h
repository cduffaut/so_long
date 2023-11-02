/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:40:53 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/01 16:41:01 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

/*-------------------- libft --------------------*/

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t count);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
int		is_valid(char *haystack, size_t i, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		is_trim(char c, const char *set);
char	*ft_strtrim(char const *s1, char const *set);
char	*cpypste(char const *s, int i, char c);
int		str_nbr(char const *s, char c);
char	**ft_split(char const *s, char c);
char	**free_split(char **tab);
char	*ft_itoa(int n);
char	*crea_nbr(long n, int neg);
int		ft_len(long n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);

/*-------------------- bonus libft --------------------*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*-------------------- ft_printf --------------------*/

int		ft_printf(const char *str, ...);
int		print_c(char c);
int		print_s(char *s);
int		prct_case(const char *str, va_list stock, int i);
int		len_nbr(int nbr);
int		ft_putnbr(int n);
int		print_hexa(unsigned long nbr, int format);
int		unsigned_len(unsigned int nbr);
int		print_u(unsigned int n);
int		print_p(long long nbr);
int		print_hexa_p(unsigned long long nbr, int format);

/*-------------------- get_next_line --------------------*/

typedef struct s_buffers
{
	int					fd;
	char				*buffer;
	struct s_buffers	*next;
	int					index;
	int					end;
}	t_buffers;
char	*get_next_line(int fd);
int		reallojoin(char **dest, int cur_size, char *src, int src_size);
int		remove_fd(t_buffers **begin_list, int fd);

#endif
