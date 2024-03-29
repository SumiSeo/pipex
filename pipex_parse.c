/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:28:21 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/29 14:17:30 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_path(char *first_cmd, char *env)
{
	char	**arr;
	int		i;

	(void)first_cmd;
	i = 0;
	printf("parsing\n");
	printf("ENV %c\n", env[i]);
	while (env[i])
	{
		arr = ft_split(&env[i], ':');
		i++;
	}
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		printf("-----\n");
		// find_path(arr[i], first_cmd, env);
		i++;
	}
	return (arr);
}

void	find_path(char *path, char *first_cmd, char **env)
{
	(void)path;
	(void)first_cmd;
	(void)env;
	// if there is correct command

	//
}