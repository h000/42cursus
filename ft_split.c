/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 16:27:31 by hpark             #+#    #+#             */
/*   Updated: 2020/04/15 17:12:57 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s1, char const c)
{
	size_t	count;

	count = 0;
	while (*s1)
	{
		while (*s1 == c)
			s1++;
		if (*s1 && *s1 != c)
			count++;
		while (*s1 && *s1 != c)
			s1++;
	}
	return (count);
}

static size_t	ft_checklen(char const *s1, char const c)
{
	size_t	count;

	count = 0;
	while (*s1 && *s1 != c)
	{
		count++;
		s1++;
	}
	return (count);
}

char			**free_res(char **result, size_t i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	if (!(result = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(result[i] = malloc(sizeof(char) * (ft_checklen(s, c) + 1))))
				return (free_res(result, i));
			j = 0;
			while (*s && *s != c)
				result[i][j++] = *s++;
			result[i][j] = '\0';
			i++;
		}
	}
	result[i] = 0;
	return (result);
}
