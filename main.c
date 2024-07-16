/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:37:02 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/15 14:37:02 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_init_stack(&a, argv + 1, argc == 2);
	if (!check_sorted_stack(a))
	{
		if (ft_stack_length(a) == 2)
			sa(&a, false);
		else if (ft_stack_length(a) == 3)
			tiny_sort(&a);
		else
			ft_push_swap(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
