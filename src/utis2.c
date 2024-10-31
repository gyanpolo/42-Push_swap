/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:12:44 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/30 14:37:39 by gpolo            ###   ########.fr       */
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

void	find_move_up(t_maxmin *maxmin, t_stack *stack_a, t_values *values)
{
	t_stack	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = stack_a;
	size = ft_lstsize(stack_a);
	while (size > 0)
	{
		if (tmp->index < maxmin->max && tmp->index >= maxmin->min)
		{
			values->moves_up = i;
			break ;
		}
		tmp = tmp->next;
		size--;
		i++;
	}
}

void	find_move_dw(t_maxmin *maxmin, t_stack *stack_a,
			t_values *values, int moves_up)
{
	t_stack	*tmp;
	int		size;
	int		j;

	j = 0;
	tmp = stack_a;
	size = ft_lstsize(stack_a);
	while (size > 0)
	{
		if (tmp->index < maxmin->max && tmp->index >= maxmin->min
			&& moves_up != j)
		{
			values->moves_dw = j;
			break ;
		}
		tmp = tmp->next;
		size--;
		j++;
	}
}

void	move_elements_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_values	values;
	t_maxmin	maxmin;

	maxmin.min = 0;
	maxmin.max = 30;
	while (*stack_a)
	{
		move_up_or_dw(&maxmin, stack_a, &values);
		move_stack(stack_a, stack_b, &values);
		update_maxmin(stack_a, &maxmin);
	}
}
