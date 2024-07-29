/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:51:23 by jesumore          #+#    #+#             */
/*   Updated: 2024/07/30 01:08:33 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

static void	ft_free_stacks(t_stack_node **a, t_stack_node **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
}

static void	ft_error(t_stack_node **a, t_stack_node **b)
{
	ft_free_stacks(a, b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	ft_commands(t_stack_node **a, t_stack_node **b, char *line_command)
{
	if (!ft_strcmp(line_command, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(line_command, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(line_command, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(line_command, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(line_command, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(line_command, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(line_command, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(line_command, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(line_command, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(line_command, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(line_command, "rrr\n"))
		rrr(a, b, true);
	else
		ft_error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				stack_len;
	char			*line;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], 32);
	ft_init_stack(&a, argv + 1, argc == 2);
	stack_len = ft_stack_length(a);
	line = get_next_line(0);
	while (line)
	{
		ft_commands(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_sorted_stack(a) && stack_len == ft_stack_length(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stacks(&a, &b);
}
