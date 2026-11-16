/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:46:00 by asaadane          #+#    #+#             */
/*   Updated: 2026/11/16 15:46:00 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

static void	*ft_free_split(int j, char **p)
{
	while (j > 0)
	{
		free(p[j]);
		j--;
	}
	free(p);
	return (NULL);
}

static int	word_len(char *str, char c, int i)
{
	int	j;

	j = 0;
	while (str[i] != c && str[i])
	{
		j++;
		i++;
	}
	return (j);
}

static size_t	word_counter(char const *str, char ch)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ch)
			i++;
		if (str[i])
			counter++;
		while (str[i] != ch && str[i])
			i++;
	}
	return (counter);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		wc;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wc = word_counter((char *)s, c);
	split = (char **)malloc((wc + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (j < wc && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		split[j] = ft_substr((char *)s, i, word_len((char *)s, c, i));
		if (!split[j])
			return (ft_free_split(j, split));
		j++;
		i = i + word_len((char *)s, c, i);
	}
	split[j] = NULL;
	return (split);
}

int	ft_count(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		i++;
	}
	return (i);
}

int	ft_count_stack(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		i++;
	}
	return (i);
}
