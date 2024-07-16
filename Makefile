# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 22:50:19 by jesumore          #+#    #+#              #
#    Updated: 2024/07/16 22:50:20 by jesumore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

SRC = errors.c ft_split.c main.c push_command.c push_swap.c \
		push_swap_utils.c reverse_rotate_command.c rotate_command.c \
  		stack_init.c stack_utils.c swap_command.c algorithm_3_5_num.c \

OBJS := $(SRC:%.c=%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
