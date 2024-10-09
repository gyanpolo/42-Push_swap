/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cecker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:41:24 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/04 16:03:56 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int valid_argv(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!(((argv[i][j] >= '0') && (argv[i][j] <= '9')) || (argv[i][j] == '-')))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	valid_ints(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((ft_strncmp("2147483647", argv[i], 10) < 0
			) && (ft_strlen(argv[i]) >= 10))
			return(0);
		if ((ft_strncmp("-2147483648", argv[i], 11) < 0
			) && (ft_strlen(argv[i]) >= 11))
			return(0);
		i++;
	}
	return (1);
}

int valid_nums(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (argv[i])
	{
		while (argv[i + j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[i + j]))
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int	checker(char **argv)
{
	if (!(1 == valid_argv(argv)))
		return (0);
	else if (!(1 == valid_ints(argv)))
		return (0);
	else if (!(1 == valid_nums(argv)))
		return (0);
	return (1);
}
