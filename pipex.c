/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:06 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/29 20:22:58 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc != 5)
		return (pipex_exit(INVALID_ARGS));
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			break ;
		env++;
	}
	printf("TEST ! \n");
	create_pipe(argv, *env + 5, env);

	return (0);
}
