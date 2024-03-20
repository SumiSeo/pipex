/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:06 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/20 19:12:28 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pingGoogle(void)
{
}

int	main(int argc, char **argv, char **envp)
{
	t_pipexdata *data;
	enum error_msg errors;
	(void)argv;
	(void)envp;
	(void)data;
	if (argc != 5)
	{
		errors = INVALID_ARGS;
		printf("Argument number is not correct %u\n", errors);
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
	return (0);
}