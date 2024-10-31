/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:12 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/31 12:46:41 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_t_lis(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	t_stack	*new;

	i = 1;
	*stack_a = ft_lstnew(ft_atoi(argv[i++]));
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	ft_lstadd_last(stack_a);
}
/*
void	print_lis(t_stack *stack_a)
{
	t_stack *current = stack_a;
	int i = 0;
	int j = ft_lstsize(stack_a);

	printf("NEXT\n");
	while (i < j)
	{
		printf("%d>>%d\n",current->num, current->index);
		current = current->next;
		i++;
	}
	printf("PREV\n");
	current = stack_a;
	i = 0;
	while (i < j)
	{
		current = current->prev;	
		printf("%d>>%d\n",current->num, current->index);
		i++;
	}
}
*/

int	main(int argc, char **argv)
{
	static t_stack	*stack_a;
	static t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (0 == checker(argv))
		return (error());
	create_t_lis(argc, argv, &stack_a);
	put_index(&stack_a);
	my_algoritm(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (1);
}
