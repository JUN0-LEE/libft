/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:26:35 by julee             #+#    #+#             */
/*   Updated: 2020/01/30 17:26:36 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_deque *		deque_init(void)
{
    return (ft_memalloc(sizeof(t_deque)));
}

void 			deque_push_front(t_deque *deque, void *content)
{
    t_dlist  *node;
    node = ft_memalloc(sizeof(t_dlist));
    node->content = content;
    if (is_empty_deque(deque))
        deque->last = node;
    else
    {
        deque->first->prev = node;
        node->next = deque->first;
    }
    deque->first = node;
}

void 			deque_push_back(t_deque *deque, void *content)
{
    t_dlist  *node;
    node = ft_memalloc(sizeof(t_dlist));
    node->content = content;
    if (is_empty_deque(deque))
        deque->first = node;
    else {
        deque->last->next = node;
        node->prev = deque->last;
    }
    deque->last = node;
}

void			deque_pop_front(t_deque *deque)
{
    if (is_empty_deque(deque))
        return ;
    t_dlist *node;
    node = deque->first;
    deque->first = node->next;
    deque->first->prev = NULL;
    free(node);
}

void			deque_pop_back(t_deque *deque)
{
    if (is_empty_deque(deque))
        return ;
    t_dlist *node;
    node = deque->last;
    deque->last = node->prev;
    deque->last->next = NULL;
    free(node);
}

void *			deque_front(t_deque *deque)
{
    if (is_empty_deque(deque))
        return (NULL);
    return (deque->first->content);
}

void *			deque_back(t_deque *deque)
{
    if (is_empty_deque(deque))
        return (NULL);
    return (deque->last->content);
}

int 			is_empty_deque(t_deque *deque)
{
    if (deque->first == NULL)
        return true;
    return false;
}

int				deque_size(t_deque *deque)
{
    int     size;
    t_dlist  *node;

    if (is_empty_deque(deque))
        return (0);
    size = 0;
    node = deque->first;
    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    return (size);
}
