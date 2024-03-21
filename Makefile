# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 14:06:51 by sumseo            #+#    #+#              #
#    Updated: 2024/03/21 18:30:27 by sumseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name
NAME = pipex


#SRCS AND OBJS FOR COMPILING

SRCS = pipex.c error_handler.c pipex_write.c pipex_parse.c
#INCLUDES = 
OBJS = $(SRCS:%.c=%.o)

#FLAGS
CC = clang
CFLAGS = -Wall -Werror -Wextra
#CLIB = 
DEBUGGER = -g3

all : $(NAME)
%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ $(DEBUGGER)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(CLIB) $(DEBUGGER)

clean : 
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME)

re : fclean all