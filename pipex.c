/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:06 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/20 19:52:06 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pingGoogle(void)
{
}

int	main(int argc, char **argv, char **env)
{
	t_pipexdata *data;
	enum error_msg errors;
	(void)argv;
	(void)env;
	(void)data;
	if (argc != 5)
	{
		errors = INVALID_ARGS;
		return (*(int *)pipex_exit(NULL, NULL, INVALID_ARGS, NULL));
	}
	if (access(argv[1], F_OK) == -1)
	{
		// file does not exist,
		errors = NO_FILE;
		printf("sorry but this file does not exist");
		// return (*(int *)pipex_exit(NULL, argv[1], NO_FILE, NULL));
	}
	if (access(argv[1], R_OK) == -1)
	{
		// I can not read the file
		errors = NO_PERMISSION;
		printf("Sorry the file is existing but I can not read the file");
		// return (*(int *)pipex_exit(NULL, argv[1], NO_PERMISSION, NULL));
	}
	char *cmd[2];
	cmd[0] = "ls";
	execve("/bin/ls", cmd, env);
	return (0);
}