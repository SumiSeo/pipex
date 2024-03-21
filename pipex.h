/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:02 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/21 18:43:57 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	NO_MEMORY
};

typedef struct s_pipexdata
{
	char	*env_path;
	char	**cmds;
	int		in_fd;
	int		out_fd;

}			t_pipexdata;

int			pipex_exit(t_pipexdata *data, char *param, int err, char ***cmd);
void		pipex_perror(char *param, int err);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		parse_path(int argc, char **argv, char **env);

#endif