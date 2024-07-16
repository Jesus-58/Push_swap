/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:33:44 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/15 14:33:44 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				length;

	length = ft_stack_length(*stack);
	if (stack == NULL || *stack == NULL || length == 1)
		return ;
	last_node = ft_find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool checker)
{
	ft_rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool checker)
{
	ft_rotate(b);
	if (!checker)
		write (1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_rotate(a);
	ft_rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}
