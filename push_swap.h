/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:30 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/09 14:30:58 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "libftprintf.h"
#include "libft.h"

typedef struct  s_values
{
	int	moves_up;
	int moves_dw;
}		t_values;

typedef struct	s_stack
{
	struct s_stack	*prev;
	int				num;
	struct s_stack	*next;
}		t_stack;

int		error(void);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_last(t_stack **lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstfirst(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	sa(t_stack **stack_a, int i);
void	sb(t_stack **stack_b, int i);
void	ss(t_stack **stack_a, t_stack **stack_b);
int		swap(t_stack **lst);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
int		push(t_stack **stack_i, t_stack **stack_p);
void	create_t_lis(int argc, char **argv, t_stack **stack_a);
void	print_lis(t_stack *stack_a);
void	ft_delete_first_node(t_stack **lst);
void	ra(t_stack **stack_a, int i);
void	rb(t_stack **stack_b, int i);
void	rr(t_stack **stack_a, t_stack **stack_b);
int		rotate(t_stack **lst);
void	rra(t_stack **stack_a, int i);
void	rrb(t_stack **stack_b, int i);
void	rrr(t_stack **stack_a, t_stack **stack_b);
int		r_rotate(t_stack **lst);
int		checker(char **argv);
void	my_algoritm(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b, int size);
int		the_lowest(t_stack **stack_a);
int		are_in_o(t_stack **stack_a);
void    rotate_to_lowest(t_stack **stack_a, int lowest);
#endif
