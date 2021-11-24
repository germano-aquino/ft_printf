/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:31:28 by grenato-          #+#    #+#             */
/*   Updated: 2021/08/21 11:31:28 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft.h"

static void	ft_calculateNumber(int numberOfDigits, int n, int isNegative,
	 char *number)
{
	while (numberOfDigits != isNegative - 1)
	{
		number[numberOfDigits] = (n % 10) + '0';
		n = n / 10;
		numberOfDigits--;
	}
	if (isNegative)
		number[0] = '-';
}

static int	ft_getNumberOfDigits(int n)
{
	int	numberOfDigits;

	numberOfDigits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		numberOfDigits++;
		n = n / 10;
	}
	return (numberOfDigits);
}

char	*ft_itoa(int n)
{
	int		numberOfDigits;
	int		isNegative;
	char	*number;

	numberOfDigits = ft_getNumberOfDigits(n);
	isNegative = 0;
	if (n < 0)
	{
		isNegative = 1;
		if (n == INT_MIN)
			return (ft_strdup("-2147483648"));
		n = -n;
	}
	number = (char *)malloc(sizeof(char) * (numberOfDigits + 1 + isNegative));
	if (number == NULL)
		return (0);
	number[numberOfDigits + isNegative] = '\0';
	if (!isNegative)
		numberOfDigits--;
	ft_calculateNumber(numberOfDigits, n, isNegative, number);
	return (number);
}
