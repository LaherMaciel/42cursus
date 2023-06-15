# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:36:42 by lwencesl          #+#    #+#              #
#    Updated: 2023/06/14 23:28:25 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
TEXTURE_C = 
ANIMATION_C = player_look.c player_walk.c collectibles_animations.c \
	floor_animations.c wall_animations.c
MAP_C = map_parser.c read_map.c
EVENTS_C = base_movs.c keycode.c destroy_window.c
INTERFACE_C = window2.c colors.c images.c

LIBFT_DIRECTORY = libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)libft.h
LIBFT = $(LIBFT_DIRECTORY)libft.a

MLX_DIRECTORY = minilibx-linux/
MLX_HEADER = $(MLX_DIRECTORY)mlx.h
MLX = $(MLX_DIRECTORY)libmlx.a

HEADERS_LIST = so_long.h
HEADER_DIRECTORY = srcs/
HEADERS =$(addprefix $(HEADER_DIRECTORY), $(HEADERS_LIST))

TEXTURES_LIST = $(TEXTURE_C)
TEXTURES_DIRECTORY = textures/
TEXTURES = $(addprefix $(TEXTURES_DIRECTORY), $(TEXTURES_LIST))

MAP_LIST = $(MAP_C)
MAP_DIRECTORY = map/
MAP = $(addprefix $(MAP_DIRECTORY), $(MAP_LIST))

EVENTS_DIRECTORY = events/
EVENTS = $(addprefix $(EVENTS_DIRECTORY), $(EVENTS_C))

ANIMATION_DIRECTORY = animation/
ANIMATION = $(addprefix $(ANIMATION_DIRECTORY), $(ANIMATION_C))

INTERFACE_DIRECTORY = interface/
INTERFACE = $(addprefix $(INTERFACE_DIRECTORY), $(INTERFACE_C))

SRCS_LIST = $(EVENTS) $(MAP) $(TEXTURES) $(ANIMATION) $(INTERFACE) main.c
SRCS_DIRECTORY = srcs/
SRCS = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

OBJECT_LIST = $(SRCS_LIST:.c=.o)
OBJECTS_DIRECTORY = objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_LIST))

CC = cc
CFLAGS = -g -Wall -Werror -Wextra 

LIBS = -L$(LIBFT_DIRECTORY) -lft $(MLX) -Imlx_linux -lX11 -lXext -lm -lz
INCLUDES = -I.$(HEADERS) -I.$(LIBFT_HEADER) -I.$(MLX_HEADER)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(TEXTURES_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(EVENTS_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(MAP_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(ANIMATION_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(INTERFACE_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	make -sC $(LIBFT_DIRECTORY) #--no-print-directory

$(MLX):
	cd $(MLX_DIRECTORY) && bash configure

clean: 
	rm -rf $(OBJECTS_DIRECTORY)
	make -sC $(LIBFT_DIRECTORY) clean #--no-print-directory

fclean: clean
	rm -rf $(NAME)
	make -sC $(LIBFT_DIRECTORY) fclean #--no-print-directory
	rm -rf $(MLX)

re: fclean
	clear && make

run: re
	./so_long

.PHONY: all clean fclean re
