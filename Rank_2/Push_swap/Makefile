# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 19:03:40 by laher_macie       #+#    #+#              #
#    Updated: 2023/05/25 17:53:44 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
SRC		:= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)
CC		= cc
RM		= rm -f
CFLAGS	= -g -Wall -Werror -Wextra

all:$(NAME)

$(NAME): run $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM)	$(OBJ)
	make -C Checker clean

fclean: clean
	$(RM)	$(NAME)
	make -C Checker fclean

re: fclean
	@clear
	$(MAKE) all

run:
	make -C Checker