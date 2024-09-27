/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:06:34 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/27 16:00:31 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
}

void    rb(t_stack **stack_b)
{
	rotate(stack_b);
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack **stack_a)
{
	r_rotate(stack_a);
}

void    rrb(t_stack **stack_b)
{
	r_rotate(stack_b);
}
