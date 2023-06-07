# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:07:37 by lwencesl          #+#    #+#              #
#    Updated: 2023/05/28 01:17:45 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_atoi.c \
	ft_isascii.c \
	ft_lstadd_front.c  \
	ft_lstmap.c \
	ft_memcpy.c \
	ft_putnbr_fd.c \
	ft_striteri.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_bzero.c \
	ft_isdigit.c \
	ft_lstclear.c \
	ft_lstnew.c \
	ft_memmove.c \
	ft_putstr_fd.c \
	ft_strjoin.c \
	ft_strncmp.c \
	ft_substr.c \
	ft_calloc.c \
	ft_isprint.c \
	ft_lstdelone.c \
	ft_lstsize.c \
	ft_memset.c \
	ft_split.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_itoa.c \
	ft_lstiter.c \
	ft_memchr.c \
	ft_putchar_fd.c \
	ft_strchr.c \
	ft_strlcpy.c \
	ft_strrchr.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_lstadd_back.c \
	ft_lstlast.c \
	ft_memcmp.c \
	ft_putendl_fd.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strstrlen.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_printf_utils.c \
	get_next_line/get_next_line_bonus.c \
	get_next_line/get_next_line_utils_bonus.c

AR = ar rc
CC = cc
RM = rm -f
CFLAGS = -g -Wall -Werror -Wextra
HEADER = -I.libft.h -I.get_next_line/get_next_line_bonus.h -I.ft_printf/ft_printf.h
FT_PRINTF_DIRECTORY = ft_printf/
GNL_DIRECTORY = get_next_line/

OBJ = $(SRC:.c=.o)
OBJECTS_DIRECTORY = bin/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJ))

all:$(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(FT_PRINTF_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(GNL_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

clean:
	$(RM) $(OBJECTS)
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	$(RM) $(NAME)

re:	fclean
	clear && make all

.PHONY: all clean fclean re