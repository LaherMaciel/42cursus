# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:07:37 by lwencesl          #+#    #+#              #
#    Updated: 2022/11/18 01:00:28 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii\
ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy\
ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd\
ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri ft_strjoin\
ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr\
ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper\

B_SRCS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast\
ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap\

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra


all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
bonus: $(B_SRCS:=.o)
			ar rc $(NAME) $(B_SRCS:=.o)
clean:
	$(RM)	$(SRC:=.o) $(B_SRCS:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)