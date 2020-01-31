/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:53:24 by julee             #+#    #+#             */
/*   Updated: 2020/01/30 23:39:58 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define BUFF_SIZE 1024

typedef enum	e_boolean
{
	false,
	true
}				t_boolean;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_node
{
	void			*content;
	struct s_node	*next;
}				t_node;

typedef struct	s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}				t_dlist;

typedef struct	s_stack
{
	t_node		*top;
}				t_stack;

typedef struct	s_queue
{
	t_node		*first;
	t_node		*last;
}				t_queue;

typedef struct	s_deque
{
	t_dlist		*first;
	t_dlist		*last;
}				t_deque;

typedef struct	s_vec
{
	void		*contents;
	size_t		capacity;
	size_t		current;
}				t_vec;

int				ft_tolower		(int c);
int				ft_toupper		(int c);
int				ft_isprint		(int c);
int				ft_isascii		(int c);
int				ft_isalnum		(int c);
int				ft_isdigit		(int c);
int				ft_isalpha		(int c);
int				ft_atoi			(const char *str);
int				ft_strcmp		(const char *s1, const char *s2);
int				ft_strncmp		(const char *s1, const char *s2, size_t n);
char			*ft_strcpy		(char *dst, const char *src);
char			*ft_strncpy		(char *dst, const char *src, size_t len);
char			*ft_strdup		(const char *s1);
size_t			ft_strlen		(const char *s);
char			*ft_strcat		(char *s1, const char *s2);
char			*ft_strncat		(char *s1, const char *s2, size_t n);
size_t			ft_strlcat		(char *dest, const char *src, size_t dstsize);
char			*ft_strstr		(const char *haystack, const char *needle);
char			*ft_strnstr		(const char *haystack, const char *needle,
				size_t len);
char			*ft_strchr		(const char *s, int c);
char			*ft_strrchr		(const char *s, int c);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *x, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

int				ft_memcmp		(const void *s1, const void *s2, size_t n);
void			*ft_memchr		(const void *s, int c, size_t n);
void			*ft_memmove		(void *dst, const void *src, size_t len);
void			*ft_memccpy		(void *dst, const void *src, int c, size_t n);
void			*ft_memcpy		(void *dst, const void *src, size_t n);
void			ft_bzero		(void *s, size_t n);
void			*ft_memset		(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);

int				ft_isspace(char c);
void			ft_putuschar(unsigned char c);
void			ft_putunichar(int n);
char			*ft_itoa_base(int n, int base);
void			ft_intmax_putnbr(intmax_t nbr);

int				get_next_line(int fd, char **line);
void			ft_swap(void *a, void *b, size_t size);

t_stack			*stack_init(void);
void			stack_pop(t_stack *stack);
void			stack_push(t_stack *stack, void *content);
void			*top(t_stack *stack);
int				is_empty_stack(t_stack *stack);
int				stack_size(t_stack *stack);

t_queue			*queue_init(void);
void			queue_push(t_queue *queue, void *content);
void			queue_pop(t_queue *queue);
void			*queue_front(t_queue *queue);
int				is_empty_queue(t_queue *queue);
int				queue_size(t_queue *queue);

t_deque			*deque_init(void);
void			deque_push_front(t_deque *deque, void *content);
void			deque_push_back(t_deque *deque, void *content);
void			deque_pop_front(t_deque *deque);
void			deque_pop_back(t_deque *deque);
void			*deque_front(t_deque *deque);
void			*deque_back(t_deque *deque);
int				is_empty_deque(t_deque *deque);
void			*deque_at(t_deque *deque, int pos);
int				deque_size(t_deque *deque);

#endif
