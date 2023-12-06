/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:33:23 by hbenazza          #+#    #+#             */
/*   Updated: 2023/11/25 10:48:52 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar(int c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}
static int	ft_forma(const char **format, int *len, va_list args)
{
	if (**format == 'c')
		ft_putcharft(va_arg(args, int), len, format);
	else if (**format == 's')
		ft_putstrft(va_arg(args, char *), len, format);
	else if (**format == 'd' || **format == 'i')
	{
		ft_putnbrft(va_arg(args, int), len);
		*format += 1;
	}
	else if (**format == 'u')
	{
		ft_putunsigned(va_arg(args, unsigned int), len);
		*format += 1;
	}
	else if (**format == 'x' || **format == 'X')
		ft_puthexadecimal(va_arg(args, unsigned int), len, format,
			format);
	else if (**format == 'p')
		ft_putpointer(va_arg(args, unsigned long long), len, format);
	else if (**format == '\0')
		return (-1);
	else if (**format == '%')
		ft_putcharft('%', len, format);
	else
	{
		ft_putchar('%', len);
		ft_putchar(**format, len);
		*formt += 1;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		length;
	int		form;
	va_list	args;

	length = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			form = ft_forma(&format, &length, args);
			if (form == -1)
				return (-1);
		}
		else
			ft_putcharft(*format, &length, &format);
	}
	va_end(args);
	return (length);
}
