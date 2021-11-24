/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:33:55 by grenato-          #+#    #+#             */
/*   Updated: 2021/08/21 11:33:55 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_getNumberOfStrings(const char *s, char c)
{
	int	counter;
	int	newStringWasCounted;
	int	i;

	counter = 0;
	i = 0;
	newStringWasCounted = 0;
	while (s[i] != '\0')
	{
		if (!newStringWasCounted && s[i] != c)
		{
			counter++;
			newStringWasCounted = 1;
		}
		if (newStringWasCounted && s[i] == c)
			newStringWasCounted = 0;
		i++;
	}
	return (counter);
}

static void	ft_getValidIndexes(char const *s, char c, int *indexes)
{
	int	index;

	index = indexes[0];
	while (s[index] == c)
		index++;
	indexes[0] = index;
	while (s[index] != c && s[index] != '\0')
		index++;
	indexes[1] = index - 1;
}

static void	ft_copyStringToPtr(char const *s, int *indexes, char *ptr)
{
	int	i;

	i = 0;
	while (i < indexes[1] - indexes[0] + 1)
	{
		ptr[i] = s[indexes[0] + i];
		i++;
	}
	ptr[i] = '\0';
	indexes[0] = indexes[1] + 1;
}

static void	ft_variablesInitiation(int *indexes)
{
	indexes[0] = 0;
	indexes[1] = 0;
	indexes[2] = 0;
}

	//ind[] is a vector of indexes where
	//ind[0] is the start index of the string to be splitted
	//ind[1] is the end index of the string to be splitted
	//ind[2] is a iterable index of split
char	**ft_split(char const *s, char c)
{
	int		ind[3];
	int		nStr;
	char	**split;

	ft_variablesInitiation(ind);
	if (s == NULL)
		return (0);
	nStr = ft_getNumberOfStrings(s, c);
	split = (char **) malloc(sizeof(char *) * (nStr + 1));
	if (split == NULL)
		return (0);
	while (ind[2] < nStr)
	{
		ft_getValidIndexes(s, c, ind);
		split[ind[2]] = (char *)malloc(sizeof(char) * (ind[1] - ind[0] + 2));
		if (split[ind[2]] == NULL)
		{
			free(split);
			return (0);
		}
		ft_copyStringToPtr(s, ind, split[ind[2]]);
		ind[2]++;
	}
	split[ind[2]] = NULL;
	return (split);
}
