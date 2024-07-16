/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:09:43 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/15 20:09:43 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sintax_error(char *string_num)
{
	if (!(*string_num == '+' || *string_num == '-'
			|| (*string_num >= '0' && *string_num <= '9')))
		return (1);
	if ((*string_num == '+' || *string_num == '-')
		&& !(string_num[1] >= '0' && string_num[1] <= '9'))
		return (1);
	while (*++string_num)
	{
		if (!(*string_num >= '0' && *string_num <= '9'))
			return (1);
	}
	return (0);
}

void	ft_free_errors(t_stack_node **a, char **argv, bool flag_if_argc_2)
{
	ft_free_stack(a);
	if (flag_if_argc_2)
		ft_free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*actual;
	t_stack_node	*temporal;

	if (stack == NULL)
		return ;
	actual = *stack;
	while (actual)
	{
		temporal = actual->next;
		free(actual);
		actual = temporal;
	}
	*stack = NULL;
}

void	ft_free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

int	ft_repetition_error(t_stack_node *a, int n)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}
