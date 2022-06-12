/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishigam <kishigam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:34:28 by kishigam          #+#    #+#             */
/*   Updated: 2022/06/12 11:41:53 by kishigam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parse(char c, va_list format)
{
	if (c == 'c')
		return (ft_putchar(va_arg(format, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(format, char *)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_putptr(va_arg(format, void *)) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (ft_putint(va_arg(format, int)));
	else if (c == 'u')
		return (ft_putuint(va_arg(format, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(format, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_parse(format[i], ap);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
