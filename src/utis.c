/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:40:05 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/31 12:32:24 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	swap(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!lst || !(*lst) || (*lst)->next == (*lst))
		return (0);
	first = *lst;
	second = (*lst)->next;
	last = (*lst)->prev;
	last->next = second;
	second->prev = last;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	*lst = second;
	return (1);
}

int	push(t_stack **stack_i, t_stack **stack_p)
{
	t_stack	*first;

	first = *stack_i;
	if (!stack_i || !(*stack_i))
		return (0);
	if (first->next == first)
		*stack_i = NULL;
	else
	{
		first->prev->next = first->next;
		first->next->prev = first->prev;
		*stack_i = first->next;
	}
	ft_lstadd_front(stack_p, first);
	return (1);
}

int	rotate(t_stack **lst)
{
	*lst = (*lst)->next;
	return (1);
}

int	r_rotate(t_stack **lst)
{
	*lst = (*lst)->prev;
	return (1);
}
