/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:41:34 by hpark             #+#    #+#             */
/*   Updated: 2020/05/13 16:05:16 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_arg(va_list arg, t_format *f)
{
	int	count;

	count = 0;
	if (f->conversion == 'c')
		count = write_arg_c(arg, f);
	if (f->conversion == 's')
		count = write_arg_s(arg, f);
	if (f->conversion == 'p')
		count = write_arg_p(arg, f);
	if (f->conversion == 'i' || f->conversion == 'd')
		count = write_arg_int(arg, f);
	if (f->conversion == 'u')
		count = write_arg_u(arg, f);
	if (f->conversion == 'x')
		count = write_arg_x(arg, f);
	if (f->conversion == 'X')
		count = write_arg_bigx(arg, f);
	if (f->conversion == '%')
		count = write_arg_pct(f);
	return (count);
}

int	write_arg_p(va_list arg, t_format *f)
{
	unsigned long int	ptr;
	int					i;
	int					count;

	i = 0;
	ptr = (unsigned long int)(va_arg(arg, void *));
	if (f->precision == 0 && ptr == 0)
	{
		i = 2;
		i = put_space(f, i);
		write(1, "0x", 2);
		return (i);
	}
	f->arg_len = putnbr_base_len(ptr, "0123456789abcdef");
	count = (f->precision > f->arg_len) ? f->precision : f->arg_len + 2;
	if (f->minus == 0)
		i += if_no_minus(f, count, 0);
	i += write(1, "0x", 2) + put_zero(f)
		+ ft_putnbr_base(ptr, "0123456789abcdef");
	if (f->minus == 1)
		i = put_space(f, i);
	return (i);
}

int	write_arg_pct(t_format *f)
{
	int	i;

	f->arg_len = 1;
	i = 0;
	if (f->minus == 0)
	{
		while (i < (f->width - 1))
		{
			put_pad(f);
			i++;
		}
	}
	i += put_zero(f) + write(1, "%", 1);
	if (f->minus == 1)
	{
		while (i < f->width)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i);
}
