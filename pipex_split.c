/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:53:59 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/24 18:02:00 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	**free_array(char **array, int count)
{
	while (count >= 0)
	{
		free(array[count]);
		count--;
	}
	free(array);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[length])
		length++;
	return (length);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;
	size_t	i;

	i = 0;
	total_size = count * size;
	if (count != 0 && total_size / count != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (i < total_size)
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char **array;
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = 0;
	array = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	j = 0;
	while (i < count_words(s, c))
	{
		while (s[k] == c)
			k++;
		j = k;
		while (s[k] && s[k] != c)
			k++;
		array[i] = (char *)ft_calloc((k - j + 1), sizeof(char));
		if (!array[i])
			return (free_array(array, i));
		ft_strlcpy(array[i++], &s[j], k - j + 1);
	}
	return (array);
}