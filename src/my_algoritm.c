/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:07:16 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/09 15:00:12 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int a;
	int b;
	int c;

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

void move_up_or_dw(int min, int max, t_stack **stack_a, t_values *values)
{
	t_stack *tmp;
	int size;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	while (size > 0)
	{
		if ((tmp->num < max) && (tmp->num > min))
		{
			values->moves_up = i;
			break;
		}
		tmp = tmp->next;
		size--;
		i++;
	}
	size = ft_lstsize(*stack_a);
	while (size > 0)
	{
		if ((tmp->num < max) && (tmp->num > min) && (i != j))
		{
			values->moves_dw = j;
			break;
		}
		tmp = tmp->next;
		size--;
		j++;
	}
}

void    sort_100(t_stack **stack_a,t_stack **stack_b)
{
	t_values	*values;
	int			min;
	int			max;

	min = 0;
	max = (ft_lstsize(*stack_a) / 5);
	while (*stack_a)
	{
		move_up_or_dw(min, max, stack_a, values);
		if (values->moves_up < values->moves_dw)
		{
			while(values->moves_up >= 0)
				ra(stack_a, 1);
			pb(stack_a, stack_b);
		} 
		else if(values->moves_up > values->moves_dw)
		{
			while(values->moves_dw >= 0)
				rra(stack_a, 1);
			pb(stack_a, stack_b);
		}
	}
}
void	my_algoritm(t_stack **stack_a, t_stack **stack_b)
{
	int lowest;

	if (ft_lstsize(*stack_a) <= 1 || are_in_o(stack_a) == 1)
		return ;
	else if(ft_lstsize(*stack_a) <= 3)
		sort_three(stack_a);
	else if(ft_lstsize(*stack_a) <= 100)
		sort_100(stack_a, stack_b);
	else
	{
		while(ft_lstsize(*stack_a) > 3)
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
