/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:54:16 by hpark             #+#    #+#             */
/*   Updated: 2020/05/13 16:05:39 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct	s_format_specifier{
	int		minus;
	int		precision;
	int		width;
	int		arg_len;
	int		zero;
	char	conversion;
}				t_format;

typedef struct	s_info{
	int	idx;
	int	str_len;
}				t_info;

int				ft_printf(const char *format, ...);
int				write_arg(va_list arg, t_format *f);
int				write_arg_c(va_list arg, t_format *f);
int				write_arg_s(va_list arg, t_format *f);
int				write_arg_p(va_list arg, t_format *f);
int				write_arg_int(va_list arg, t_format *f);
int				write_arg_u(va_list arg, t_format *f);
int				write_arg_x(va_list arg, t_format *f);
int				write_arg_bigx(va_list arg, t_format *f);
int				write_arg_pct(t_format *f);
int				ft_putnbr_base(unsigned long int n, char *base);
int				ft_putnbr_dec(int n);
char			*ft_strchr(const char *s, int c);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
int				ft_putnstr(char *s, int n);
int				putnbr_len(int n);
int				putnbr_base_len(unsigned long int n, char *base);
int				write_arg_num(unsigned int n,
		t_format *f, char *base, int sign);
int				put_zero(t_format *f);
int				put_minus(int sign);
void			put_pad(t_format *f);
int				put_space(t_format *f, int i);
int				if_no_minus(t_format *f, int count, int sign);

#endif
