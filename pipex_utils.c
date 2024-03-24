/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:43:08 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/24 17:44:14 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) == '\0' || *(unsigned char *)(s1
				+ i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s != 0)
	{
		s++;
		length++;
	}
	return (length);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!little || little[0] == '\0')
		return ((char *)(big));
	if (!big)
		return ((char *)(big + i));
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && i + j < len)
		{
			if (little[j] != big[i + j])
				break ;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}