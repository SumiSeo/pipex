/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:02 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/29 14:18:59 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
// note that unistd is linux specific library
# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>

// #define INVALID_ARGS "Arguments are invalid";

enum		error_msg
{
	INVALID_ARGS,
	NO_FILE,
	NO_PERMISSION,
	NO_MEMORY,
	NO_PATH,
	PIPE_ISSUE,
	FORK_ISSUE
};

typedef struct s_pipexdata
{
	char	**env_path;
	char	**cmds;
	int		in_fd;
	int		out_fd;

}			t_pipexdata;

int			pipex_exit(t_pipexdata *data, char *param, enum error_msg err,
				char ***cmd);
void		pipex_perror(char *param, enum error_msg err);
void		create_pipe(char **argv, char *env);
char		**parse_path(char *first_cmd, char *env);
void		execute_child_pipe(char *cmd, char **env);
void		find_path(char *path, char *first_cmd, char **env);

#endif