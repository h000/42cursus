/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:48:19 by hpark             #+#    #+#             */
/*   Updated: 2020/05/13 15:54:07 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long int n, char *base)
{
	char	c;
	int		count;
	size_t	len;

	len = ft_strlen(base);
	count = 1;
	if (n >= len)
		count = ft_putnbr_base(n / len, base) + 1;
	c = base[n % len];
	write(1, &c, 1);
	return (count);
}

int	putnbr_base_len(unsigned long int n, char *base)
{
	int		count;
	size_t	len;

	len = ft_strlen(base);
	count = 1;
	if (n >= len)
		count = putnbr_base_len(n / len, base) + 1;
	return (count);
}
