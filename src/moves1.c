/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:06:34 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/04 12:18:56 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, int i)
{
	i += rotate(stack_a);
	if (i == 2)
		ft_printf("ra\n");
}

void    rb(t_stack **stack_b, int i)
{
	i += rotate(stack_b);
	if (i == 2)
		ft_printf("rb\n");
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}

void	rra(t_stack **stack_a, int i)
{
	i += r_rotate(stack_a);
	if (i == 2)
		ft_printf("rra\n");
}

void    rrb(t_stack **stack_b, int i)
{
	r_rotate(stack_b);
	if (i == 2)
		ft_printf("rrb\n");
}
