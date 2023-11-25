/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:28:20 by hbenazza          #+#    #+#             */
/*   Updated: 2023/11/24 20:55:09 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

static void	ft_hexa(unsigned int n, int *len)
{
	if (n >= 16)
	{
		ft_hexa(n / 16, len);
		ft_hexa(n % 16, len);
	}
	else
	{
		if (n >= 10)
			ft_putchar(n + 55, len);
		else
			ft_putchar(n + 48, len);
	}
}

static void	ft_hexadecimal(unsigned int n, int *len)
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

void	ft_puthexadecimal(unsigned int n, int *len, const char **p,
		const char **format)
{
	if (**p == 'X')
	{
		ft_hexa(n, len);
		*format += 1;
	}
	else if (**p == 'x')
	{
		ft_hexadecimal(n, len);
		*format += 1;
	}
}
