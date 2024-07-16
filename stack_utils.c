/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:37:11 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/15 14:37:11 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_append_node(t_stack_node **stack, int num)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = num;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	ft_stack_length(t_stack_node *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = 0;
	while (stack)
	{
		++i;
		stack = stack->next;
	}
	return (i);
}

t_stack_node	*ft_find_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest_node;
	long			smallest;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*ft_return_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
