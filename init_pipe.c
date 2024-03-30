/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:33:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/30 16:38:00 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_parent(int *pipe_fd, char **argv, char *path, char **env)
{
	int	fd_out;

	wait(0);
	close(pipe_fd[1]);
	fd_out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_out == -1)
		pipex_exit(NO_FILE);
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		parse_path(argv[3], path, env);
	}
	close(pipe_fd[0]);
}

void	create_pipe(char **argv, char *path, char **env)
{
	int	pipe_fd[2];
	int	id;
	int	fd_in;

	if (pipe(pipe_fd) == -1)
		pipex_exit(PIPE_ISSUE);
	id = fork();
	if (id == 0)
	{
		close(pipe_fd[0]);
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in == -1)
			pipex_exit(NO_FILE);
		else
		{
			dup2(fd_in, STDIN_FILENO);
			dup2(pipe_fd[1], STDOUT_FILENO);
			parse_path(argv[2], path, env);
		}
		close(pipe_fd[1]);
	}
	else
		fork_parent(pipe_fd, argv, path, env);
}
