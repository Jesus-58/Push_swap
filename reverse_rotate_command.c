/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_comand.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:01:46 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/16 20:01:46 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				length;

	length = ft_stack_length(*stack);
	if (stack == NULL || (*stack) == NULL || length == 1)
		return ;
	last_node = ft_find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool checker)
{
	ft_reverse_rotate(a);
	if (!checker)
		write (1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker)
{
	ft_reverse_rotate(b);
	if (!checker)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (!checker)
		write (1, "rrr\n", 4);
}
