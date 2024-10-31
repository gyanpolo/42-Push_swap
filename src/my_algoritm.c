/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:07:16 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/31 12:31:14 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->num;
	b = (*stack_a)->next->num;
	c = (*stack_a)->next->next->num;
	if (a > b && b < c && a < c)
		sa(stack_a, 1);
	else if (a > b && b > c)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, 1);
}

void	put_index(t_stack **stack_a)
{
	int	lowest;
	int	first;
	int	i;

	i = 0;
	first = (*stack_a)->num;
	lowest = the_lowest(stack_a);
	while (lowest != (the_highest(stack_a)))
	{
		while ((*stack_a)->num != lowest)
			*stack_a = (*stack_a)->next;
		(*stack_a)->index = i++;
		lowest = the_next_lowest(stack_a, lowest);
	}
	while ((*stack_a)->num != lowest)
		*stack_a = (*stack_a)->next;
	(*stack_a)->index = i++;
	lowest = the_next_lowest(stack_a, lowest);
	while ((*stack_a)->num != first)
		*stack_a = (*stack_a)->next;
}

void	move_up_or_dw(t_maxmin *maxmin, t_stack **stack_a, t_values *values)
{
	find_move_up(maxmin, *stack_a, values);
	find_move_dw(maxmin, *stack_a, values, values->moves_up);
}

void	sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int			lowest;

	move_elements_to_b(stack_a, stack_b);
	while (ft_lstsize(*stack_b))
	{
		lowest = the_highest(stack_b);
		rotate_to_lowest(stack_b, lowest);
		pa(stack_a, stack_b);
	}
}

void	my_algoritm(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest;

	if (ft_lstsize(*stack_a) <= 1 || are_in_o(stack_a) == 1)
		return ;
	else if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a, 1);
	else if (ft_lstsize(*stack_a) <= 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) >= 100)
		sort_100(stack_a, stack_b);
	else
	{
		while (ft_lstsize(*stack_a) > 3)
		{
			lowest = the_lowest(stack_a);
			rotate_to_lowest(stack_a, lowest);
			pb(stack_a, stack_b);
		}
		sort_three(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
