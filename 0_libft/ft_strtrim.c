/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 16:20:14 by hpark             #+#    #+#             */
/*   Updated: 2020/04/21 17:39:06 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_trim_len1(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			break ;
	}
	return (i);
}

static size_t	check_trim_len2(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	while (s1[len - i - 1])
	{
		if (ft_strchr(set, s1[len - i - 1]))
			i++;
		else
			break ;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	t_len1;
	size_t	t_len2;
	size_t	len;

	t_len1 = check_trim_len1(s1, set);
	t_len2 = check_trim_len2(s1, set);
	len = ft_strlen(s1);
	if (len == t_len1)
		len = 0;
	else
		len = len - t_len1 - t_len2;
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i++ < t_len1)
		s1++;
	i = 0;
	while (i < len)
		result[i++] = *s1++;
	result[i] = '\0';
	return (result);
}
