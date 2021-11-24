/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:33:39 by grenato-          #+#    #+#             */
/*   Updated: 2021/08/21 11:33:40 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_handleNegatives(int *nbr, int fd)
{
	write(fd, "-", 1);
	if (*nbr == -2147483648)
	{
		write(fd, "2147483648", 10);
		*nbr = 0;
	}
	*nbr = -*nbr;
}

void	ft_putnbr_fd(int n, int fd)
{
	char		dig;
	long int	tenPower;
	int			firstDigitNoZero;

	tenPower = 10000000000;
	firstDigitNoZero = 0;
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
		ft_handleNegatives(&n, fd);
	while (tenPower)
	{
		dig = (n / tenPower) + '0';
		if (firstDigitNoZero || dig != '0')
		{
			firstDigitNoZero = 1;
			write(fd, &dig, 1);
		}
		n = n % tenPower;
		tenPower = tenPower / 10;
	}
}
