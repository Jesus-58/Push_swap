/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:42:15 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/15 14:42:15 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack_node **head)
{
	int	length;

	length = ft_stack_length(*head);
	if (head == NULL || *head == NULL || length == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a, bool checker)
{
	ft_swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool checker)
{
	ft_swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_swap(a);
	ft_swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
