/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:49:15 by charles           #+#    #+#             */
/*   Updated: 2020/10/15 19:49:18 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	initializer(t_format *s)
{
	s->zero = 0;
	s->minus = 0;
	s->width = 0;
	s->prec = -1;
	s->plus = 0;
	s->hashtag = 0;
	s->space = 0;
}

void	ft_read(char *fmt, t_format *s)
{
	int i;

	i = -1;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			i++;
			initializer(s);
			parsing(s, fmt, &i);
			if (!fmt[i])
				return ;
			check_types(fmt, i, s);
			if (fmt[i + 1])
				i++;
			else
				return ;
		}
		if (fmt[i] != '%')
			ft_putchar(fmt[i], s);
		else
			i--;
	}
}

int		ft_printf(const char *format, ...)
{
	char			*fmt;
	t_format		s;

	if (!format || !*format)
		return (0);
	fmt = (char*)format;
	s.ret = 0;
	initializer(&s);
	va_start(s.arg, format);
	ft_read(fmt, &s);
	va_end(s.arg);
	return (s.ret);
}
