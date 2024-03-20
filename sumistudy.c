/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sumistudy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:06 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/20 17:19:09 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pingGoogle(void)
{
}

int	main(void)
{
	int id = fork();
	printf("ID :  %d\n", id);
	if (id == -1)
	{
		return (1);
	}
	if (id == 0)
	{
		printf("I am in the child process\n");
		int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1)
		{
			printf("Could not find progrm to executed\n");
			return (2);
		}
	}
	else
	{
		int waitstatus;
		wait(&waitstatus);
		if (WIFEXITED(waitstatus))
		{
			int statusCode = WEXITSTATUS(waitstatus);
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