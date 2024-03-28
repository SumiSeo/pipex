# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 14:06:51 by sumseo            #+#    #+#              #
#    Updated: 2024/03/28 14:34:46 by sumseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name
NAME = pipex


#SRCS AND OBJS FOR COMPILING

SRCS = pipex.c error_handler.c pipex_parse.c init_pipe.c child_pipe.c
INCLUDES = libft/
OBJS = $(SRCS:%.c=%.o)

#FLAGS
CC = clang
CFLAGS = -Wall -Werror -Wextra
CLIB = -L libft/ -l libft
DEBUGGER = -g3

all : $(NAME)
%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ $(DEBUGGER)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME) $(CLIB) $(DEBUGGER)

clean : 
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME)

re : fclean all