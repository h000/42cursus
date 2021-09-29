/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:43:26 by hpark             #+#    #+#             */
/*   Updated: 2020/04/15 16:44:56 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa2(long n, char *s, int len)
{
	int	i;

	i = 0;
	if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		s[len - i - 1] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	s[len] = '\0';
	return (s);
}

char		*ft_itoa(int n)
{
	long	num;
	char	*result;
	int		len;

	num = n < 0 ? (-1 * (long)n) : n;
	len = ft_itoa_len(num) + (n < 0 ? 1 : 0);
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	if (n < 0)
		result[0] = '-';
	result = ft_itoa2(num, result, len);
	return (result);
}
