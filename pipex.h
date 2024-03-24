/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:31:02 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/24 18:21:00 by sumseo           ###   ########.fr       */
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
	char	**path_arr;
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
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strnstr(const char *big, const char *little, size_t len);
size_t		count_words(char const *s, char c);
char		**free_array(char **array, int count);
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t count, size_t size);

#endif