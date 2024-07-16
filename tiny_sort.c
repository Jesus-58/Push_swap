/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:34:14 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/17 18:34:14 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sorted_stack(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack_node	*ft_find_highest_node(t_stack_node *stack)
{
	t_stack_node	*highest_node;
	int				highest;

	if (stack == NULL)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = ft_find_highest_node(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	handle_five_num(t_stack_node **a, t_stack_node **b)
{
	while (ft_stack_length(*a) > 3)
	{
		ft_nodes_init(*a, *b);
		ft_finish_rotation(a, ft_find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
