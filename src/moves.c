/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:00:31 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/04 12:19:37 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int i)
{
	i += swap(stack_a);
	if (i == 2)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b, int i)
{
	i += swap(stack_b);
	if (i == 2)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = push(stack_b ,stack_a);
	if (i == 1)
		ft_printf("pa\n");
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = push(stack_a ,stack_b);
	if (i == 1)
		ft_printf("pb\n");
}
