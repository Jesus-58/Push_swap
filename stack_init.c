/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:10:25 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/15 20:10:25 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *string)
{
	long	num;
	int		i;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	while (string[i] && (string[i] == ' ' || string[i] == '\t'
			|| string[i] == '\n' || string[i] == '\v'
			|| string[i] == '\f' || string[i] == '\r'))
		i++;
	if (string[i] == '+')
		i++;
	else if (string[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		num = (num * 10) + (string[i] - '0');
		i++;
	}
	return (num * sign);
}

void	ft_init_stack(t_stack_node **a, char **argv, bool flag_if_argc_2)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_sintax_error(argv[i]))
			ft_free_errors(a, argv, flag_if_argc_2);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_free_errors(a, argv, flag_if_argc_2);
		if (ft_repetition_error(*a, (int)num))
			ft_free_errors(a, argv, flag_if_argc_2);
		ft_append_node(a, (int)num);
		++i;
	}
	if (flag_if_argc_2)
		ft_free_matrix(argv);
}
