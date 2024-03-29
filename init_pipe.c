/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:33:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/29 14:18:56 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(char **argv, char *env)
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
		int fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putendl_fd("File is not corect", 2);
		}
		else
		{
			printf("File is correct\n");
			dup2(fd, STDIN_FILENO);
			// dup2(STDOUT_FILENO, pipe_fd[1]);
			printf("%s\n", env);
			parse_path(argv[1], env);
		}
		close(pipe_fd[1]);
	}
	else
	{
		close(pipe_fd[1]);
		printf("I am parent process\n");
		sleep(1);
		// printf("TEST parent %d\n", pipe_fd[1]);
		// printf("TEST parent %d\n", pipe_fd[0]);
		close(pipe_fd[0]);
	}
}