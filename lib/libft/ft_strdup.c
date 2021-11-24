/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:34:02 by grenato-          #+#    #+#             */
/*   Updated: 2021/08/21 11:34:02 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*newStr;
	int		length;

	length = 0;
	while (str[length] != '\0')
		length++;
	newStr = malloc((length + 1) * sizeof(char));
	if (!newStr)
		return (0);
	length = 0;
	while (str[length] != '\0')
	{
		newStr[length] = str[length];
		length++;
	}
	newStr[length] = '\0';
	return (newStr);
}
