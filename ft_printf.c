/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:32:54 by hpark             #+#    #+#             */
/*   Updated: 2020/05/13 15:57:34 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_value(const char *format, va_list arg, t_info *s)
{
	int n;

	n = 0;
	if (format[s->idx] == '*')
	{
		n = va_arg(arg, int);
		s->idx++;
	}
	else
	{
		while (ft_strchr("0123456789", format[s->idx]))
			n = n * 10 + (format[s->idx++] - 48);
	}
	return (n);
}

void	get_pwidth(const char *format, va_list arg, t_info *s, t_format *f)
{
	while (format[s->idx] == '0')
	{
		s->idx++;
		f->zero = 1;
	}
	if (ft_strchr("*.123456789", format[s->idx]))
	{
		f->width = get_value(format, arg, s);
		if (f->width < 0)
		{
			f->minus = 1;
			f->width *= -1;
		}
		if (format[s->idx] == '.')
		{
			s->idx++;
			f->precision = get_value(format, arg, s);
		}
	}
}

t_info	*ft_print_specifier(const char *format, va_list arg, t_info *s)
{
	t_format	*f;

	if ((f = malloc(sizeof(t_format))) == 0)
		return (0);
	ft_bzero(f, sizeof(t_format));
	f->precision = -1;
	while (format[s->idx] == '-')
	{
		f->minus = 1;
		s->idx++;
	}
	f->zero = 0;
	get_pwidth(format, arg, s, f);
	if (ft_strchr("cspiduxX%", format[s->idx]))
	{
		f->conversion = format[s->idx];
		s->str_len += write_arg(arg, f);
	}
	else
		s->str_len = -1;
	free(f);
	return (s);
}

int		ft_print(const char *format, va_list arg, t_info *s)
{
	while (format[s->idx])
	{
		while (format[s->idx] && format[s->idx] != '%')
		{
			write(1, &format[s->idx++], 1);
			s->str_len++;
		}
		if (format[s->idx] && format[s->idx++] == '%')
		{
			s = ft_print_specifier(format, arg, s);
			if (s->str_len == -1)
				return (-1);
			s->idx++;
		}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_info	*s;
	int		ret;

	va_start(arg, format);
	if ((s = malloc(sizeof(t_info))) == 0)
		return (0);
	ft_bzero(s, sizeof(t_info));
	if (ft_print(format, arg, s) == -1)
		return (-1);
	ret = s->str_len;
	free(s);
	va_end(arg);
	return (ret);
}
