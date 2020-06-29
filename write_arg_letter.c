/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg_letter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:47:51 by hpark             #+#    #+#             */
/*   Updated: 2020/05/13 16:23:26 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_arg_c(va_list arg, t_format *f)
{
	char	c;
	int		count;

	count = 0;
	c = va_arg(arg, int);
	if (f->minus == 0)
	{
		while (count < f->width - 1)
		{
			put_pad(f);
			count++;
		}
	}
	write(1, &c, 1);
	count++;
	if (f->minus == 1)
	{
		while (count < f->width)
		{
			write(1, " ", 1);
			count++;
		}
	}
	return (count);
}

int	write_arg_s(va_list arg, t_format *f)
{
	char	*s;
	int		i;
	int		n;

	if (!(s = va_arg(arg, char *)))
		s = "(null)";
	f->arg_len = ft_strlen(s);
	n = (f->precision < 0 || f->precision > f->arg_len) ?
		f->arg_len : f->precision;
	i = 0;
	if (f->minus == 0)
	{
		while (i < (f->width - n))
		{
			write(1, " ", 1);
			i++;
		}
	}
	i += ft_putnstr(s, n);
	if (f->minus == 1)
		i = put_space(f, i);
	return (i);
}
