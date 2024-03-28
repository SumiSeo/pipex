/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:33:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/28 21:51:36 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(char **argv, char **env)
{
	int pipe_fd[2];

	(void)env;
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
		int fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("File is not corect");
		}
		else
		{
			dup2(fd, STDIN_FILENO);
			dup2(STDOUT_FILENO, pipe_fd[1]);
			printf("Dup called");
		}
		close(pipe_fd[1]);
	}
	else
	{
		close(pipe_fd[1]);
		printf("I am parent process\n");
		sleep(1);
		printf("TEST parent %d\n", pipe_fd[1]);
		printf("TEST parent %d\n", pipe_fd[0]);
		close(pipe_fd[0]);
	}
}