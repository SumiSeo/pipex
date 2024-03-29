/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:28:21 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/29 16:30:17 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_path(char *first_cmd, char *path, char **env)
{
	char	**arr;
	char	**cmds;

	arr = ft_split(path, ':');
	cmds = parse_cmd(first_cmd);
	execute_cmd(first_cmd, cmds, arr, env);
}

char	**parse_cmd(char *cmd)
{
	char	**cmds;

	cmds = ft_split(cmd, ' ');
	return (cmds);
}
void	execute_cmd(char *cmd, char **cmds, char **arr, char **env)
{
	int		i;
	char	*joined_path;
	char	*path;
	char	*joined_cmd;

	path = "/";
	i = 0;
	while (arr[i])
	{
		joined_cmd = ft_strjoin(path, cmd);
		joined_path = ft_strjoin(arr[i], joined_cmd);
		if (access(joined_path, X_OK | F_OK) == 0)
			break ;
		i++;
	}
	// // char cm
	// printf("TEST %s\n", joined_path);
	// printf("ENV CHECK %s\n", env[0]);
	printf("------EXECVE DOWN BELOW-----");
	execve(joined_path, cmds, env);
}
