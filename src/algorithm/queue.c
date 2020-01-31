/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:26:19 by julee             #+#    #+#             */
/*   Updated: 2020/01/30 20:48:59 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_queue			*queue_init(void)
{
	return (ft_memalloc(sizeof(t_queue)));
}

void			queue_push(t_queue *queue, void *content)
{
	t_node *node;

	node = ft_memalloc(sizeof(t_node));
	node->content = content;
	if (is_empty_queue(queue))
		queue->first = node;
	else
		queue->last->next = node;
	queue->last = node;
}

void			queue_pop(t_queue *queue)
{
	t_node	*front;

	if (is_empty_queue(queue))
		return ;
	front = queue->first;
	queue->first = front->next;
	if (queue->first == NULL)
		queue->last = NULL;
	free(front);
}

void			*queue_front(t_queue *queue)
{
	if (is_empty_queue(queue))
		return (NULL);
	return (queue->first->content);
}

int				is_empty_queue(t_queue *queue)
{
	if (queue->first == NULL)
		return (true);
	return (false);
}

int				queue_size(t_queue *queue)
{
	int		size;
	t_node	*node;

	if (is_empty_queue(queue))
		return (0);
	size = 0;
	node = queue->first;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}
