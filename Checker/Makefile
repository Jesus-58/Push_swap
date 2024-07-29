# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 18:46:40 by jesumore          #+#    #+#              #
#    Updated: 2024/07/29 21:15:15 by jesumore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc

CCFLAGS = -Wall -Wextra -Werror -g

PUSH_SWAP = ../libpush_swap.a

SRCS = checker.c get_next_line.c get_next_line_utils.c

OBJS := $(SRCS:%.c=%.o)

RM = rm -f

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(PUSH_SWAP)
	$(CC) $^ -o $(NAME)
	cp $(NAME) ../

$(PUSH_SWAP):
	cd ../ && make

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	cd ../ && $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re