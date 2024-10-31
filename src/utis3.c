/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:37:49 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/31 14:26:05 by gpolo            ###   ########.fr       */
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

void	rotate_to_lowest_b(t_stack **stack_b, int lowest)
{
	int		size;
	int		pos;
	t_stack	*temp;

	size = ft_lstsize(*stack_b);
	pos = 0;
	temp = *stack_b;
	while (temp)
	{
		if (temp->num == lowest)
			break ;
		temp = temp->next;
		pos++;
	}
	if (pos <= size / 2)
		while ((*stack_b)->num != lowest)
			rb(stack_b, 1);
	else
		while ((*stack_b)->num != lowest)
			rrb(stack_b, 1);
}
