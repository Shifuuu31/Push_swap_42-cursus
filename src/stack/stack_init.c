/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:46:00 by asaadane          #+#    #+#             */
/*   Updated: 2026/11/16 15:46:00 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_stacks(t_stack *stack, t_size *size, char **splited)
{
	int	i;

	stack->a = (int *)malloc(sizeof(int) * (size->a + 1));
	if (!stack->a)
	{
		free_arguments(splited, size->a);
		exit (1);
	}
	size->b = 0;
	stack->b = (int *)malloc(sizeof(int) * (size->a + 1));
	if (!stack->b)
	{
		free(stack->a);
		free_arguments(splited, size->a);
		exit (1);
	}
	i = 0;
	while (i < size->a)
	{
		check_sign(splited[i]);
		stack->a[i] = ft_atoi(splited[i]);
		i++;
	}
}

void	free_arguments(char **splited, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	ft_free_all(t_stack *stack, t_size *size, char **splited)
{
	free(stack->a);
	free(stack->b);
	free(stack);
	free_arguments(splited, size->a);
	free(size);
}
