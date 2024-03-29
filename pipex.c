/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:06 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/29 15:21:01 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// t_pipexdata	*pipex_get_data(int argc, char **argv, int here_doc, char **env)
// {
// 	t_pipexdata		*data;
// 	int				i;
// 	enum error_msg	errors;

// 	i = 0;
// 	data = malloc(sizeof(struct s_pipexdata));
// 	if (!data)
// 	{
// 		errors = NO_MEMORY;
// 		pipex_exit(data, NULL, NO_MEMORY, NULL);
// 	}
// 	data->env_path = NULL;
// 	data->cmds = NULL;
// 	data->in_fd = open(argv[1], O_RDONLY);
// 	if (data->in_fd == -1)
// 		return (pipex_exit(data, argv[1], NO_FILE, NULL), data);
// 	if (!here_doc)
// 		data->out_fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
// 	if (access(argv[argc - 1], F_OK) == 01)
// 		pipex_exit(data, argv[argc - 01], NO_FILE, NULL);
// 	else if (access(argv[argc - 1], W_OK) == -1)
// 		pipex_exit(data, argv[argc - 1], NO_PERMISSION, NULL);
// 	// data->env_path = parse_path(argc, argv, env);
// 	return (data);
// 	// if (!data->env_path)
// 	// 	return (pipex_exit(data, NULL, NO_PATH, NULL));
// }
int	main(int argc, char **argv, char **env)
{
	t_pipexdata	*data;

	// char			*cmd[2];
	(void)argv;
	(void)data;
	if (argc != 5)
	{
		return (pipex_exit(NULL, NULL, INVALID_ARGS, NULL));
	}
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			break ;
		env++;
	}
	printf("ENV %s\n", *env + 5);
	create_pipe(argv, *env + 5, env);
	// cmd[0] = "ls";
	// execve("/bin/ls", cmd, env);
	// create pipe line
	return (0);
}
