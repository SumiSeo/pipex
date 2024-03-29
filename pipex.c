/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:06 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/21 18:27:44 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipexdata	*pipex_get_data(int argc, char **argv, int here_doc, char **env)
{
	t_pipexdata		*data;
	int				i;
	enum error_msg	errors;

	(void)here_doc;
	(void)argv;
	(void)argc;
	(void)env;
	i = 0;
	data = malloc(sizeof(struct s_pipexdata));
	if (!data)
	{
		errors = NO_MEMORY;
		pipex_exit(data, NULL, NO_MEMORY, NULL);
	}
	data->env_path = NULL;
	data->cmds = NULL;
	data->in_fd = open(argv[1], O_RDONLY);
	printf("file int ? %d\n", data->in_fd);
	return (data);
}
int	main(int argc, char **argv, char **env)
{
	t_pipexdata		*data;
	enum error_msg	errors;

	// char			*cmd[2];
	(void)argv;
	(void)data;
	if (argc != 5)
	{
		errors = INVALID_ARGS;
		return (pipex_exit(NULL, NULL, INVALID_ARGS, NULL));
	}
	if (access(argv[1], F_OK) == -1)
	{
		errors = NO_FILE;
		return (pipex_exit(NULL, argv[1], NO_FILE, NULL));
	}
	if (access(argv[1], R_OK) == -1)
	{
		errors = NO_PERMISSION;
		return (pipex_exit(NULL, argv[1], NO_PERMISSION, NULL));
	}
	// data = pipex_get_data(argc, argv, 0, env);
	// parse environment path
	parse_path(argc, argv, env);
	// cmd[0] = "ls";
	// execve("/bin/ls", cmd, env);
	return (0);
}
