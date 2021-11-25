/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:10:35 by grenato-          #+#    #+#             */
/*   Updated: 2021/11/24 23:58:45 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char flag, va_list *ap)
{
	int	len;

	len = 0;
	if (flag == 'c')
		len += ft_print_char(ap);
	else if (flag == 's')
		len += ft_print_string(ap);
	else if (flag == 'd' || flag == 'i')
		len += ft_print_int(ap);
	else if (flag == 'p')
		len += ft_print_add(ap);
	else if (flag == 'u')
		len += ft_print_positive_int(ap);
	else if (flag == 'x')
		len += ft_print_low_hex(ap);
	else if (flag == 'X')
		len += ft_print_up_hex(ap);
	else if (flag == '%')
	{
		len++;
		write(1, "%", 1);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	flag;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			len++;
		}
		else
		{
			format++;
			flag = *format;
			len += ft_print_arg(flag, &ap);
		}
		format++;
	}
	va_end(ap);
	return (len);
}
