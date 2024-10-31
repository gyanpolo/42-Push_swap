/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:34:17 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/31 11:22:57 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}*/

void	ft_lstclear(t_stack **lst)
{
	while (lst && *lst)
	{
		ft_delete_first_node(lst);
	}
}

void	ft_delete_first_node(t_stack **lst)
{
	t_stack	*first;

	first = *lst;
	if (first->next == first)
		*lst = NULL;
	else
	{
		first->prev->next = first->next;
		first->next->prev = first->prev;
		*lst = first->next;
	}
	free(first);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*first;
	t_stack	*last;

	if (!lst || !(*lst))
	{
		new->next = new;
		new->prev = new;
		*lst = new;
	}
	else
	{
		first = *lst;
		last = (*lst)->prev;
		new->next = first;
		new->prev = last;
		last->next = new;
		first->prev = new;
		*lst = new;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int		count;
	t_stack	*current;

	if (!lst)
		return (0);
	count = 1;
	current = lst->next;
	while (current != lst)
	{
		count++;
		current = current->next;
	}
	return (count);
}
