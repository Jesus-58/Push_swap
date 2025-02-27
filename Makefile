# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 22:50:19 by jesumore          #+#    #+#              #
#    Updated: 2024/07/29 21:30:15 by jesumore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBRARY = libpush_swap.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

CC_LIB = ar -rcs

SRC = errors.c ft_split.c main.c push_command.c push_swap.c \
		push_swap_utils.c reverse_rotate_command.c rotate_command.c \
  		stack_init.c stack_utils.c swap_command.c algorithm_3_5_num.c \

OBJS := $(SRC:%.c=%.o)

RM = rm -f

all: $(NAME) $(LIBRARY)

$(NAME): $(LIBRARY)
	$(CC) $< -o $@

$(LIBRARY): $(OBJS)
	$(CC_LIB) $(LIBRARY) $^

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

bonus:
	cd Checker/ && make

clean:
	$(RM) $(OBJS) $(LIBRARY)

fclean: clean
	$(RM) $(NAME)
	cd Checker/ && make fclean

re: fclean all

.PHONY: all clean fclean re
