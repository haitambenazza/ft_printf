/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:14 by hbenazza          #+#    #+#             */
/*   Updated: 2023/11/23 18:12:23 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putunsigned(unsigned int n, int *len)
{
	if (n > 10)
	{
		ft_putunsigned(n / 10, len);
		ft_putunsigned(n % 10, len);
	}
	else
	{
		ft_putchar(n + '0', len);
	}
}
