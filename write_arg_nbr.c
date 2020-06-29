/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:43:06 by hpark             #+#    #+#             */
/*   Updated: 2020/05/13 16:22:48 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_arg_int(va_list arg, t_format *f)
{
	unsigned int	num;
	int				n;
	int				sign;

	sign = 0;
	n = va_arg(arg, int);
	if (n < 0)
	{
		num = -1 * n;
		sign = 1;
	}
	else
		num = n;
	return (write_arg_num(num, f, "0123456789", sign));
}

int	write_arg_u(va_list arg, t_format *f)
{
	unsigned int	n;

	n = va_arg(arg, int);
	return (write_arg_num(n, f, "0123456789", 0));
}

int	write_arg_x(va_list arg, t_format *f)
{
	unsigned int	n;

	n = va_arg(arg, int);
	return (write_arg_num(n, f, "0123456789abcdef", 0));
}

int	write_arg_bigx(va_list arg, t_format *f)
{
	unsigned int	n;

	n = va_arg(arg, int);
	return (write_arg_num(n, f, "0123456789ABCDEF", 0));
}

int	write_arg_num(unsigned int n, t_format *f, char *base, int sign)
{
	int	i;
	int	count;

	i = 0;
	if (f->precision == 0 && n == 0)
		return (put_space(f, i));
	f->arg_len = putnbr_base_len(n, base);
	count = (f->precision > f->arg_len) ? f->precision : f->arg_len;
	if (f->minus == 0)
		i += if_no_minus(f, count, sign);
	if (f->minus == 1)
		i += put_minus(sign);
	i += put_zero(f) + ft_putnbr_base(n, base);
	if (f->minus == 1)
		i = put_space(f, i);
	return (i);
}
