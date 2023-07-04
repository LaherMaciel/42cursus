# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:36:42 by lwencesl          #+#    #+#              #
#    Updated: 2023/07/04 23:31:51 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
TEXTURE_C =
ANIMATION_C = player_look.c player_walk.c collectibles_animations.c \
	floor_animations.c wall_animations.c exit_animation.c
MAP_C = map_validation.c map_validation2.c read_map.c
EVENTS_C = base_movs.c keycode.c prints.c
INTERFACE_C = window.c main_image.c pixeis.c destroy_window.c destroy_window2.c\
		vals_init.c secundary_images_adjusts.c secundary_images_adjusts_2.c

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
CFLAGS = -g -Wall -Werror -Wextra -fsanitize=address

LIBS = -L$(LIBFT_DIRECTORY) -lft $(MLX) -Imlx_linux -lX11 -lXext -lm -lz
INCLUDES = -I.$(HEADERS) -I.$(LIBFT_HEADER) -I.$(MLX_HEADER)

# COLORS
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
RESET   = \033[0m

$(NAME): $(LIBFT) $(MLX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)
	@make norm -s
	@echo "[" "$(GREEN)OK$(RESET)" "] | so_long created!"

$(OBJECTS_DIRECTORY):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Creating objects..."
	@mkdir -p $(OBJECTS_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)$(TEXTURES_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)$(EVENTS_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)$(MAP_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)$(ANIMATION_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)$(INTERFACE_DIRECTORY)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Objects ready!"

$(OBJECTS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling libft..."
	@make -sC $(LIBFT_DIRECTORY) > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] | Libft ready!"


$(MLX):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling minilibx..."
	@cd $(MLX_DIRECTORY) && bash configure > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] | Minilibx ready!"

clean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing object files...$(RESET)"
	@rm -rf $(OBJECTS_DIRECTORY)
	@make -sC $(LIBFT_DIRECTORY) clean > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean: clean
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing binary files...$(RESET)"
	@rm -rf $(NAME)
	@make -sC $(LIBFT_DIRECTORY) fclean > /dev/null 2>&1
	@rm -rf $(MLX)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Binary file removed."

norm:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Norminetting...$(RESET)"
	@if norminette srcs/ libft/ images/ | grep -q "Error!" ; then \
	    echo "[" "$(RED)!!$(RESET)" "] | Norminette found errors.$(RESET)"; \
	    norminette srcs/ libft/ images/ | awk '/Error!/ {print "[ " "$(RED)!!$(RESET)" " ] | " $$0}'; \
	else \
	    echo "[" "$(GREEN)OK$(RESET)" "] | Norminette passed!"; \
	fi

re: fclean
	clear && make -s

run: re
	./so_long mapa3.ber

multi_run: re
	./so_long progressive.ber progressive2.ber progressive5.ber progressive4.ber \
		progressive3.ber progressive6.ber 42_logo.ber

multi_full_valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./so_long \
		progressive.ber progressive2.ber progressive5.ber progressive4.ber progressive3.ber \
		progressive6.ber 42_logo.ber

map3:./so_long mapa3.ber

dbug: re
	gdb -tui -args ./so_long mapa3.ber mapa4.ber

val:re
	valgrind ./so_long mapa3.ber mapa4.ber

val_full:re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./so_long mapa3.ber

ver: re norm
	valgrind ./so_long

.PHONY: all clean fclean re
