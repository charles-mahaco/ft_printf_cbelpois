/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:50:14 by charles           #+#    #+#             */
/*   Updated: 2020/10/15 19:50:17 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_d_justify_left(int d, t_format *s, int len, int strlen)
{
	if (d < 0)
	{
		s->plus = 0;
		if (d != -2147483648)
		{
			ft_putchar('-', s);
			d *= -1;
		}
		else
			len++;
	}
	else if (s->plus == 1)
		ft_putchar('+', s);
	while (s->prec-- > len)
		ft_putchar('0', s);
	ft_putnbr(d, s, len);
	if (!(d == 0 && s->prec == -1))
		s->width -= strlen;
	while (s->width-- > 0)
		ft_putchar(' ', s);
}

void	print_d_justify_right(int d, t_format *s, int len, int strlen)
{
	if (d < 0 && (s->zero == 1 && s->prec < 0))
	{
		s->plus = 0;
		ft_putchar('-', s);
		d *= -1;
	}
	else if (s->plus == 1 && (s->zero == 1 && s->prec < 0))
	{
		ft_putchar('+', s);
		s->plus = 0;
	}
	while (s->width-- > strlen)
		(s->zero == 1 && s->prec < 0 ? ft_putchar('0', s) : ft_putchar(' ', s));
	if (d < 0)
	{
		s->plus = 0;
		ft_putchar('-', s);
		d *= -1;
	}
	else if (s->plus == 1)
		ft_putchar('+', s);
	while (s->prec-- > len)
		ft_putchar('0', s);
	(d == 0 && s->width == 0 && s->prec == -1 ? ft_putchar(' ', s) :
												ft_putnbr(d, s, len));
}

void	print_d(t_format *s)
{
	int d;
	int len;
	int strlen;

	d = (int)va_arg(s->arg, int);
	len = ft_putnbr_size(d);
	strlen = ((s->prec > 0 && s->prec > len) ? s->prec : len);
	if (d >= 0 && s->space && !s->plus)
	{
		ft_putchar(' ', s);
		s->width--;
	}
	(d < 0 || s->plus == 1 ? s->width-- : 0);
	if (s->minus == 1 || s->width < strlen)
		print_d_justify_left(d, s, len, strlen);
	else
		print_d_justify_right(d, s, len, strlen);
}

void	print_u(t_format *s)
{
	long int	u;
	int			len[2];

	u = va_arg(s->arg, unsigned int);
	(u < 0 ? u += 4294967296 : u);
	len[0] = (ft_putnbr_size(u));
	len[1] = ((s->prec > 0 && s->prec > len[0]) ? s->prec : len[0]);
	if (s->minus == 1 || s->width < len[1])
	{
		while (s->prec-- > len[0])
			ft_putchar('0', s);
		ft_putnbr(u, s, len[0]);
		if (!(u == 0 && s->prec == -1))
			s->width -= len[1];
		while (s->width-- > 0)
			ft_putchar(' ', s);
	}
	else
	{
		while (s->width-- > len[1])
			ft_putchar((s->zero == 1 && s->prec < 0 ? '0' : ' '), s);
		while (s->prec-- > len[0])
			ft_putchar('0', s);
		u == 0 && s->prec == -1 ? ft_putchar(' ', s) : ft_putnbr(u, s, len[0]);
	}
}
