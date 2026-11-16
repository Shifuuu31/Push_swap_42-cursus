/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:46:00 by asaadane          #+#    #+#             */
/*   Updated: 2026/11/16 15:46:00 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty_arg(char **splited)
{
	int		count;

	count = 0;
	while (splited[count])
	{
		count++;
	}
	if (count == 0)
		ft_put_error();
}

void	check_sign(char *splited)
{
	int	i;

	i = 0;
	if (ft_strlen(&splited[i]) > 12)
	{
		ft_put_error();
	}
	if (splited[i] == '-' || splited[i] == '+')
		i++;
	if (splited[i] == '\0')
	{
		ft_put_error();
	}
	while (splited[i] != '\0')
	{
		if (!ft_isdigit(splited[i]))
		{
			ft_put_error();
		}
		i++;
	}
}

void	ft_check_duplicate(int *stack_a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a - 1)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (stack_a[i] == stack_a[j])
			{
				ft_put_error();
			}
			j++;
		}
		i++;
	}
}

bool	ft_check_sorted(int *stack_a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}
