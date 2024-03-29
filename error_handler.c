/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:25:47 by sumseo            #+#    #+#             */
/*   Updated: 2024/03/29 19:03:42 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex_exit(enum e_error_msg err)
{
	if (err < 3)
		pipex_perror(err);
	return (err);
}

void	pipex_perror(enum e_error_msg err)
{
	ft_putstr_fd("OOPSY *_* ! I am R2 ... I a m analy..zing... problem:", 2);
	ft_putchar_fd('\n', 2);
	if (err == INVALID_ARGS)
	{
		ft_putstr_fd("You put the wrong number of arguments :-(\n", 2);
	}
	else if (err == NO_FILE)
	{
		ft_putstr_fd("I can not find the file you want to access :-(\n \n", 2);
	}
	else if (err == NO_PERMISSION)
	{
		ft_putstr_fd("I don't have permission for this file :-(\n", 2);
	}
	else if (err == NO_MEMORY)
	{
		ft_putstr_fd("I can not allocate memory correctly to the malloc :-(\n",
			2);
	}
}
