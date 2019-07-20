/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:52:08 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/20 17:28:34 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define OP_SIZE sizeof(long)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putcharerr(char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *s, int len);
void				ft_putstrerr(char *str);
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memdup(void *src, size_t size);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_isspace(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putendl(char const *s);
void				ft_putnendl(char const *s, int len);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnstr_fd(char const *s, int len, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnendl_fd(char const *s, int len, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *nlist);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_isupper(int c);
char				*ft_strcapitalize(char *s);
char				*ft_strndup(const char *s1, size_t n);

unsigned			ft_swap_integer(unsigned nbr);

#endif
