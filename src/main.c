/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:03:52 by asaadane          #+#    #+#             */
/*   Updated: 2026/11/16 15:46:00 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *stack, t_size *size, char **splited)
{
	if (size->a <= 5)
		ft_small_sort(stack, size);
	else if (size->a <= 100)
		large_sort(stack, size, 5);
	else
		large_sort(stack, size, 11);
	ft_free_all(stack, size, splited);
}

int	main(int ac, char **av)
{
	char	**splited;
	t_stack	*stack;
	t_size	*size;

	stack = malloc(sizeof(t_stack));
	size = malloc(sizeof(t_size));
	if (ac < 2)
		exit(1);
	count_argv(av, &size->a);
	splited = split_arguments(ac, av, &size->a);
	check_empty_arg(splited);
	load_stacks(stack, size, splited);
	if (size->a <= 1)
	{
		free_arguments(splited, size->a);
		exit (1);
	}
	ft_check_duplicate(stack->a, size->a);
	if (ft_check_sorted(stack->a, size->a))
	{
		ft_free_all(stack, size, splited);
		exit(1);
	}
	sorting(stack, size, splited);
	return (0);
}
