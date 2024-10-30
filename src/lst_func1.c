/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:34:17 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/29 13:19:47 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(&(lst->num));
	free(lst);
}

void	free_content(void *content)
{
	free(content);
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
