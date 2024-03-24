/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:28:21 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/24 18:12:36 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_path(int argc, char **argv, char **env)
{
	printf("Parsing-path function called\n");
	printf("argc %d\n", argc);
	printf("argv %s\n", argv[1]);
	char *path_dir;
	char **arr;

	int i;
	char *path = "PATH";

	i = 0;
	// have to find path
	// loop over all the environment variable and then find lines which starts with "PATH"
	while (env[i])
	{
		if (ft_strncmp(env[i], path, ft_strlen(path)) == 0)
		{
			arr = ft_split(env[i], ':');
			path_dir = env[i];
			printf("Path directory %s\n", path_dir);
		}

		i++;
	}

	i = 0;
	int j;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			printf("%c", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}