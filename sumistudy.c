/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sumistudy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:06 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/21 16:56:45 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(void)
{
	int	id;
	int	err;
		int waitstatus;
	int	statusCode;

	id = fork();
	printf("ID :  %d\n", id);
	if (id == -1)
	{
		return (1);
	}
	if (id == 0)
	{
		printf("I am in the child process\n");
		err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1)
		{
			printf("Could not find progrm to executed\n");
			return (2);
		}
	}
	else
	{
		wait(&waitstatus);
		if (WIFEXITED(waitstatus))
		{
			statusCode = WEXITSTATUS(waitstatus);
			if (statusCode == 0)
			{
				printf("Success\n");
			}
			else
			{
				printf("Failure with status Code : %d\n", statusCode);
			}
		}
		printf("------------------------------------------------------------------------\n");
		printf("Some post processing goes here ! \n");
	}
	printf("***TESTEST***\n");
	return (0);
}



int	main2(int argc, char **argv, char **env)
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