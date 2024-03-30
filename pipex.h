/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:02 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/30 16:07:35 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

enum	e_error_msg
{
	INVALID_ARGS,
	NO_FILE,
	NO_PERMISSION,
	NO_MEMORY,
	NO_PATH,
	PIPE_ISSUE,
	FORK_ISSUE,
	COMMAND_ISSUE
};

int		pipex_exit(enum e_error_msg err);
void	pipex_perror(enum e_error_msg err);
void	create_pipe(char **argv, char *path, char **env);
void	parse_path(char *first_cmd, char *path, char **env);
char	**parse_cmd(char *cmd);
void	execute_cmd(char **cmds, char **arr, char **env);
#endif