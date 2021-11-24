/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:10:35 by grenato-          #+#    #+#             */
/*   Updated: 2021/11/22 23:28:37 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_count_args(char *format)
{
	char	*iter;
	int		num_args;

	num_args = 0;
	iter = format;
	while(iter)
	{
		if (*iter == '%' && *(iter + 1) != '%')
			num_args++;
		iter++;
	}
	return (num_args);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	char	*ch;
	int		num_of_args;

	num_of_args = ft_count_args(format);
	va_start(ap, num_of_args);
	
}