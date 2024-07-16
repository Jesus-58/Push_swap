/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:06:52 by jesumore          #+#    #+#             */
/*   Updated: 2024/07/16 22:49:40 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					pos;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}				t_stack_node;	

char			**ft_split(char *string, char c);
void			ft_init_stack(t_stack_node **a, char **argv,
					bool flag_if_argc_2);
void			ft_nodes_init(t_stack_node *a, t_stack_node *b);
void			ft_set_position(t_stack_node *stack);
void			ft_set_price(t_stack_node *a, t_stack_node *b);
void			ft_set_cheapest(t_stack_node *b);
int				ft_sintax_error(char *string_num);
void			ft_free_errors(t_stack_node **a, char **argv,
					bool flag_if_argc_2);
void			ft_free_stack(t_stack_node **stack);
void			ft_free_matrix(char **argv);
int				ft_repetition_error(t_stack_node *a, int n);
void			ft_append_node(t_stack_node **stack, int num);
t_stack_node	*ft_find_last_node(t_stack_node *head);
bool			check_sorted_stack(t_stack_node *stack);
int				ft_stack_length(t_stack_node *stack);
t_stack_node	*ft_find_smallest(t_stack_node *stack);
t_stack_node	*ft_return_cheapest(t_stack_node *stack);
void			ft_finish_rotation(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);
void			tiny_sort(t_stack_node **a);
void			ft_push_swap(t_stack_node **a, t_stack_node **b);
void			handle_five_num(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);

#endif
