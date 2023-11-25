/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:30:41 by hbenazza          #+#    #+#             */
/*   Updated: 2023/11/25 10:50:35 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putcharft(char c, int *len, const char **p);
void	ft_putstrft(char *str, int *len, const char **p);
void	ft_putnbrft(int n, int *len);
void	ft_putunsigned(unsigned int n, int *len);
void	ft_puthexadecimal(unsigned int n, int *len, const char **p,
			const char **format);
void	ft_putpointer(unsigned long long n, int *len, const char **p);

#endif
