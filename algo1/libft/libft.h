/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:07:41 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/07 13:02:48 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>

# define BUFF_SIZE 10
# define NB_FD 255

typedef struct		s_lol
{
	void			*content;
	char			*path;
	size_t			content_size;
	struct s_lol	*next;
}					t_lol;

int					ft_abs(int nb);
int					ft_atoi(char *str);
int					ft_base_10(char *str, char *base);
void				ft_bzero(void *s, size_t n);
void				ft_deltab(void **data);
void				exiting(char *msg);
int					ft_get_char(char *s, char c);
int					ft_get_rank(int *tablo, int value, int size);
int					ft_gnl(int fd, char **line);
int					ft_higher(int a, int b);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
int					ft_lower(int a, int b);
void				ft_lstadd(t_lol **alst, t_lol *new);
void				ft_lstdel(t_lol **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_lol **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_lol *lst, void (*f)(t_lol *elem));
t_lol				*ft_lstmap(t_lol *lst, t_lol *(*f)(t_lol *elem));
t_lol				*ft_lstnew(void const *content, size_t content_size);
int					ft_max(int *itab, int size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s1, int c, size_t len);
int					ft_min(int *itab, int size);
int					ft_nblen(int n);
int					ft_nb_len_base(int n, int base);
int					ft_power(int nb, int power);
void				ft_print_n_char(char c, int n);
char				*ft_ptrf(char *str, ...);
void				ft_putchar(char c);
void				ft_putchar_fd(char d, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnb_base(int n, char *base);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				**ft_realloc(char **var, int add, int del);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s1, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *s1, const char *s2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
char				*ft_strdup_del(const char *str);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *c));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_del(char const *s1, char const *s2, int del);
size_t				ft_strlen(const char *c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strrchr(const char *s1, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_swap(void **a, void **b);
void				ft_tabnew(int *itab, int size);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_write_fd(char *str, int fd);

#endif
