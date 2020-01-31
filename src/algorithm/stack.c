/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:32:09 by julee             #+#    #+#             */
/*   Updated: 2020/01/30 20:56:09 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_stack			*stack_init(void)
{
	return (ft_memalloc(sizeof(t_stack)));
}

void			stack_pop(t_stack *stack)
{
	t_node	*top;

	if (is_empty_stack(stack))
		return ;
	else
	{
		top = stack->top;
		stack->top = top->next;
		free(top);
	}
}

void			stack_push(t_stack *stack, void *content)
{
	t_node *node;

	node = ft_memalloc(sizeof(t_node));
	node->content = content;
	if (!is_empty_stack(stack))
		node->next = stack->top;
	stack->top = node;
}

void			*top(t_stack *stack)
{
	if (is_empty_stack(stack))
		return (NULL);
	return (stack->top->content);
}

int				is_empty_stack(t_stack *stack)
{
	if (stack->top == NULL)
		return (true);
	return (false);
}

int				stack_size(t_stack *stack)
{
	int		size;
	t_node	*node;

	if (is_empty_stack(stack))
		return (0);
	node = stack->top;
	size = 0;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}
