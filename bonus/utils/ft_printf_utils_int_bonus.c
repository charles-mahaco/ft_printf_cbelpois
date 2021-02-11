/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_int_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:50:40 by charles           #+#    #+#             */
/*   Updated: 2020/10/15 19:50:43 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int		ft_putnbr_size(long int n)
{
	long int	nbr;
	int			len;

	len = 0;
	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	if (n == 0)
		len++;
	return (len);
}

int		ft_puthex_size(unsigned long long x)
{
	int len;

	len = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		x /= 16;
		len++;
	}
	return (len);
}
