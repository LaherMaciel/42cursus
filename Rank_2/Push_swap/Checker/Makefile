# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 19:22:56 by lwencesl          #+#    #+#              #
#    Updated: 2023/05/25 09:58:17 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker
SRC		:= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)
CC		= cc
RM		= rm -f
CFLAGS	= -g -Wall -Werror -Wextra

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM)	$(OBJ)

fclean: clean
	$(RM)	$(NAME)

re: fclean
	@clear
	$(MAKE) all