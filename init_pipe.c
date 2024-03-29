/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:33:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/29 16:56:21 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(char **argv, char *path, char **env)
{
	int pipe_fd[2];

	// stdin : pipe_fd[0] : read end of the file
	// stdout : pipe_fd[1] : write end of the file

	if (pipe(pipe_fd) == -1)
		pipex_exit(NULL, NULL, PIPE_ISSUE, NULL);

	int id;

	id = fork();

	if (id == 0)
	{
		close(pipe_fd[0]);
		printf("I am child process\n");
		int fd_in = open(argv[1], O_RDONLY);
		if (fd_in == -1)
		{
			ft_putendl_fd("Infile is not corect", 2);
		}
		else
		{
			printf("File is correct\n");
			dup2(fd_in, STDIN_FILENO);
			// dup2(STDOUT_FILENO, pipe_fd[1]);
			dup2(pipe_fd[1], STDOUT_FILENO);
			parse_path(argv[2], path, env);
			printf("ORDER CHECK");
		}
		close(pipe_fd[1]);
	}
	else
	{
		printf("I am parent process\n");
		wait(0);
		printf("****I was waiting until child process end\n ");
		close(pipe_fd[1]);
		int fd_out = open(argv[4], O_WRONLY | O_APPEND | O_CREAT, 0644);
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
			// dup2(STDOUT_FILENO, fd_out);
		}
		close(pipe_fd[0]);
	}
}