/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:56:56 by hbenazza          #+#    #+#             */
/*   Updated: 2023/11/24 21:32:55 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstrft(char *str, int *len, const char **p)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*len += 6;
		*p += 1;
		return ;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		*len += 1;
	}
	*p += 1;
}
