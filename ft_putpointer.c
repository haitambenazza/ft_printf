/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:53:25 by hbenazza          #+#    #+#             */
/*   Updated: 2023/11/25 10:48:03 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

static void	ft_hexadecimal(unsigned long long n, int *len)
{
	if (n >= 16)
	{
		ft_hexadecimal(n / 16, len);
		ft_hexadecimal(n % 16, len);
	}
	else
	{
		if (n >= 10)
			ft_putchar(n + 87, len);
		else
			ft_putchar(n + 48, len);
	}
}

void	ft_putpointer(unsigned long long n, int *len, const char **format)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		*len += 5;
		*format += 1;
	}
	else
	{
		write(1, "0x", 2);
		*len += 2;
		ft_hexadecimal(n, len);
		*format += 1;
	}
}
