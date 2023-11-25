/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:13:43 by hbenazza          #+#    #+#             */
/*   Updated: 2023/11/24 18:23:07 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putnbrft(int n, int *len)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar('-', len);
		ln = (-ln);
	}
	if (ln >= 10)
	{
		ft_putnbrft(ln / 10, len);
		ft_putnbrft(ln % 10, len);
	}
	else
	{
		ft_putchar(ln + '0', len);
	}
}
