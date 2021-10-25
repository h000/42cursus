/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:17:39 by hpark             #+#    #+#             */
/*   Updated: 2020/05/13 16:27:06 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_space(t_format *f, int i)
{
	while (i < (f->width))
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		put_zero(t_format *f)
{
	int	i;

	i = 0;
	if (f->precision > f->arg_len)
	{
		while (i < f->precision - f->arg_len)
		{
			write(1, "0", 1);
			i++;
		}
	}
	return (i);
}

int		put_minus(int sign)
{
	if (sign == 1)
	{
		write(1, "-", 1);
		return (1);
	}
	return (0);
}

void	put_pad(t_format *f)
{
	if (f->zero == 0 || f->precision != -1)
	{
		write(1, " ", 1);
	}
	else if (f->zero == 1)
	{
		write(1, "0", 1);
	}
}

int		if_no_minus(t_format *f, int count, int sign)
{
	int	i;

	i = 0;
	if (f->zero == 0 || f->precision > -1)
	{
		while (i < (f->width - count - sign))
		{
			write(1, " ", 1);
			i++;
		}
		i += put_minus(sign);
	}
	else
	{
		i += put_minus(sign);
		while (i < (f->width - count))
		{
			write(1, "0", 1);
			i++;
		}
	}
	return (i);
}
