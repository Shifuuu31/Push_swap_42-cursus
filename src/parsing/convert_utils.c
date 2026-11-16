/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:46:00 by asaadane          #+#    #+#             */
/*   Updated: 2026/11/16 15:46:00 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

void	ft_put_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

static int	ft_atoi_tool(char *str)
{
	int	result;
	int	negative;

	result = 0;
	negative = 1;
	if (!str || !*str)
		ft_put_error();
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		negative *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str)
		ft_put_error();
	return (result * negative);
}

int	ft_atoi(char *str)
{
	long int	result;

	result = ft_atoi_tool(str);
	if (INT_MIN <= result && result <= INT_MAX)
		return (result);
	else
		ft_put_error();
	return (0);
}
