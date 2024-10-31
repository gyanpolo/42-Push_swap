/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:37:49 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/30 14:39:34 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack(t_stack **stack_a, t_stack **stack_b, t_values *values)
{
	if (values->moves_up < values->moves_dw)
	{
		while (values->moves_up-- > 0)
			ra(stack_a, 1);
	}
	else
	{
		while (values->moves_dw-- > 0)
			rra(stack_a, 1);
	}
	pb(stack_a, stack_b);
}

void	update_maxmin(t_stack **stack_a, t_maxmin *maxmin)
{
	if (no_max_min(stack_a, maxmin->max, maxmin->min) == 1)
	{
		maxmin->min = maxmin->max;
		maxmin->max += 30;
	}
}
