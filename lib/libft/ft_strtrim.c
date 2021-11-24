/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:34:33 by grenato-          #+#    #+#             */
/*   Updated: 2021/08/21 11:34:37 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_isCharInSet(char chr, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_getStrTrimLength(char const *str, char const *set)
{
	int	startIndex;
	int	endIndex;

	startIndex = 0;
	while (ft_isCharInSet(str[startIndex], set))
		startIndex++;
	if (str[startIndex] == '\0')
		return (0);
	endIndex = startIndex;
	while (str[endIndex] != '\0')
		endIndex++;
	endIndex--;
	while (ft_isCharInSet(str[endIndex], set))
		endIndex--;
	return (endIndex - startIndex + 1);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		len;
	int		startIndex;
	int		i;
	char	*ptr;

	if (str == NULL)
		return (0);
	len = ft_getStrTrimLength(str, set);
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (0);
	startIndex = 0;
	while (ft_isCharInSet(str[startIndex], set))
		startIndex++;
	i = 0;
	while (i < len)
	{
		ptr[i] = str[startIndex + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
