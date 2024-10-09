/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:59:02 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/09 15:00:19 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_printf("rrr\n");
}

int	the_lowest(t_stack **stack_a)
{
	int		low;
	int		size;
	t_stack	*stack_i;
	
	stack_i = *stack_a;
	low = stack_i->num;
	size = ft_lstsize(*stack_a);
	while (size > 0)
	{
		if (stack_i->num < low)
			low = stack_i->num;
		stack_i = stack_i->next;
		size--;
	}
	return (low);
}

void	rotate_to_lowest(t_stack **stack_a, int lowest)
{
	int size;
	int pos;
	t_stack *temp;

	size = ft_lstsize(*stack_a);
	pos = 0;
	temp = *stack_a;
	while (temp)
	{
		if (temp->num == lowest)
			break;
		temp = temp->next;
		pos++;
	}
	if (pos <= size / 2)
		while ((*stack_a)->num != lowest)
			ra(stack_a, 1);
	else
		while ((*stack_a)->num != lowest)
			rra(stack_a, 1);
}

int	are_in_o(t_stack **stack_a)
{
	int size;
	t_stack *temp;

	size = ft_lstsize(*stack_a);
	temp = *stack_a;

	while (size > 1)
	{
		if (temp->num > temp->next->num)
			return (0);
		size--;
		temp = temp->next;
	}
	return (1);
}

