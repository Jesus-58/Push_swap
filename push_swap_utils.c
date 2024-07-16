/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:31:48 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/19 11:31:48 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_position(t_stack_node *stack)
{
	int	middle_line;
	int	i;

	i = 0;
	if (stack == NULL)
		return ;
	middle_line = ft_stack_length(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= middle_line)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	ft_set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*actual_a;
	t_stack_node	*target_node;
	long			fav_index;

	while (b)
	{
		fav_index = LONG_MAX;
		actual_a = a;
		while (actual_a)
		{
			if (actual_a->value > b->value
				&& actual_a->value < fav_index)
			{
				fav_index = actual_a->value;
				target_node = actual_a;
			}
			actual_a = actual_a->next;
		}
		if (fav_index == LONG_MAX)
			b->target_node = ft_find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	ft_set_price(t_stack_node *a, t_stack_node *b)
{
	int	length_a;
	int	length_b;

	length_a = ft_stack_length(a);
	length_b = ft_stack_length(b);
	while (b)
	{
		b->cost = b->pos;
		if (!(b->above_median))
			b->cost = length_b - (b->pos);
		if (b->target_node->above_median)
			b->cost += b->target_node->pos;
		else
			b->cost += length_a - (b->target_node->pos);
		b = b->next;
	}
}

void	ft_set_cheapest(t_stack_node *b)
{
	t_stack_node	*best_node;
	long			more_cheap;

	if (b == NULL)
		return ;
	more_cheap = LONG_MAX;
	while (b)
	{
		if (b->cost < more_cheap)
		{
			more_cheap = b->cost;
			best_node = b;
		}
		b = b->next;
	}
	best_node->cheapest = true;
}

void	ft_nodes_init(t_stack_node *a, t_stack_node *b)
{
	ft_set_position(a);
	ft_set_position(b);
	ft_set_target_node(a, b);
	ft_set_price(a, b);
	ft_set_cheapest(b);
}
