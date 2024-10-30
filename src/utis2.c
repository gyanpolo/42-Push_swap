/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:12:44 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/29 13:15:25 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	the_highest(t_stack **stack_a)
{
	int		hig;
	int		size;
	t_stack	*stack_i;

	stack_i = *stack_a;
	hig = stack_i->num;
	size = ft_lstsize(*stack_a);
	while (size > 0)
	{
		if (stack_i->num > hig)
			hig = stack_i->num;
		stack_i = stack_i->next;
		size--;
	}
	return (hig);
}

int	the_next_lowest(t_stack **stack_a, int lowest)
{
	int		low;
	t_stack	*stack_i;

	stack_i = *stack_a;
	low = INT_MAX;
	while (stack_i->next != *stack_a)
	{
		if ((stack_i->num > lowest) && (stack_i->num < low))
			low = stack_i->num;
		stack_i = stack_i->next;
	}
	if (stack_i->num > lowest && stack_i->num < low)
		low = stack_i->num;
	return (low);
}
