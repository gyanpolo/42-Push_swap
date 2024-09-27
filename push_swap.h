/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:30 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/27 15:55:34 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "libftprintf.h"
#include "libft.h"

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
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **lst);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_i, t_stack **stack_p);
void	create_t_lis(int argc, char **argv, t_stack **stack_a);
void	print_lis(t_stack *stack_a);
void	ft_delete_first_node(t_stack **lst);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **lst);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	r_rotate(t_stack **lst);

#endif
