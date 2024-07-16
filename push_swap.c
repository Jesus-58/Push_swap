/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:11:56 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/19 20:11:56 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_stacks(t_stack_node **a, t_stack_node **b,
								t_stack_node *cheap_node)
{
	while (*a != cheap_node->target_node && *b != cheap_node)
		rr(a, b, false);
	ft_set_position(*a);
	ft_set_position(*b);
}

static void	ft_reverse_rotate_stacks(t_stack_node **a, t_stack_node **b,
										t_stack_node *cheap_node)
{
	while (*a != cheap_node->target_node && *b != cheap_node)
		rrr(a, b, false);
	ft_set_position(*a);
	ft_set_position(*b);
}

void	ft_finish_rotation(t_stack_node **stack, t_stack_node *top_node,
								char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	ft_move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap_node;

	cheap_node = ft_return_cheapest(*b);
	if (cheap_node->above_median && cheap_node->target_node->above_median)
		ft_rotate_stacks(a, b, cheap_node);
	else if (!(cheap_node->above_median)
		&& !(cheap_node->target_node->above_median))
		ft_reverse_rotate_stacks(a, b, cheap_node);
	ft_finish_rotation(b, cheap_node, 'b');
	ft_finish_rotation(a, cheap_node->target_node, 'a');
	pa(a, b, false);
}

void	ft_push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*small_node;
	int				length_a;

	length_a = ft_stack_length(*a);
	if (length_a == 5)
		handle_five_num(a, b);
	else
	{
		while (length_a-- > 3)
			pb(b, a, false);
	}
	tiny_sort(a);
	while (*b)
	{
		ft_nodes_init(*a, *b);
		ft_move_nodes(a, b);
	}
	ft_set_position(*a);
	small_node = ft_find_smallest(*a);
	if (small_node->above_median)
		while (*a != small_node)
			ra(a, false);
	else
		while (*a != small_node)
			rra(a, false);
}
