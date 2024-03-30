/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:33:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/29 20:25:43 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// stdin : pipe_fd[0] : read end of the file
// stdout : pipe_fd[1] : write end of the file

void	create_pipe(char **argv, char *path, char **env)
{
	int	pipe_fd[2];
	int	id;
	int	fd_in;
	int	fd_out;

	if (pipe(pipe_fd) == -1)
		printf("ERROR");
	id = fork();
	if (id == 0)
	{
		close(pipe_fd[0]);
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in == -1)
		{
			// pipex_exit(NO_FILE);
			ft_putendl_fd("Infile is not corect", 2);
			// If in-file does not exist I have to quit child program but parent should continue
		}
		else
		{
			printf("Infile is correct\n");
			dup2(fd_in, STDIN_FILENO);
			dup2(pipe_fd[1], STDOUT_FILENO);
			parse_path(argv[2], path, env);
		}
		close(pipe_fd[1]);
	}
	else
	{
		wait(0);
		printf("PARENTTT\n");
		close(pipe_fd[1]);
		fd_out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd_out == -1)
		{
			ft_putendl_fd("Outfile is not correct", 2);
		}
		else
		{
			ft_putendl_fd("Outfile is corect", 2);
			dup2(pipe_fd[0], STDIN_FILENO);
			dup2(fd_out, STDOUT_FILENO);
			parse_path(argv[3], path, env);
		}
		close(pipe_fd[0]);
	}
}
