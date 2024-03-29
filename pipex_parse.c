/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:28:21 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/29 14:40:13 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_path(char *first_cmd, char *env)
{
	char	**arr;

	arr = ft_split(env, ':');
	execute_cmd(first_cmd, arr);
}

void	execute_cmd(char *cmd, char **arr)
{
	int	i;

	printf("COMMAND %s", cmd);
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		printf("-----\n");
		i++;
	}
}
