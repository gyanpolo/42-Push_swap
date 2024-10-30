/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:11:40 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/29 13:20:39 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)calloc(sizeof(t_stack), 1);
	if (!new_node)
		return (0);
	new_node->prev = NULL;
	new_node->num = content;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_lstfirst(t_stack *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_last(t_stack **lst)
{
	t_stack	*last;
	t_stack	*first;

	last = ft_lstlast(*lst);
	first = ft_lstfirst(*lst);
	last->next = first;
	first->prev = last;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->prev = *lst;
	}
	else
	{
		last = ft_lstlast(*lst);
		if (!last)
			return ;
		last->next = new;
		new->prev = last;
	}
}
