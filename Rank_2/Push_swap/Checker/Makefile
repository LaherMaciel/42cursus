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

HEADER_LIST = checker.h
HEADER_DIRECTORY = checker_srcs/
HEADERS = $(addprefix $(HEADER_DIRECTORY), $(HEADER_LIST))

SRCS_LIST = bonus_run_modes.c error_management_bonus.c error_management.c errors_bonus.c \
main.c moviments.c moviments2.c sort.c proxy.c ft_strchr.c\
stack_work.c stack_work2.c visualizer.c ft_lstsize_rem.c ft_lstnew_rem.c 
SRCS_DIRECTORY = checker_srcs/
SRC = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

LIBFT_DIRECTORY = ../libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)libft.h
LIBFT = $(LIBFT_DIRECTORY)libft.a

OBJECT_LIST = $(SRCS_LIST:.c=.o)
OBJECTS_DIRECTORY = objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_LIST))

CC = cc
CFLAGS = -g -pthread #-fsanitize=address

LIBS = -L$(LIBFT_DIRECTORY) -lft
INCLUDES = -I.$(HEADERS) -I.$(LIBFT_HEADER)

# COLORS
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
GRAY    = \033[1;90m
RESET   = \033[0m

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@if $(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME); \
	then \
		echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] | Objects ready!$(RESET)"; \
		make norm -s; \
		echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] | $(NAME) created!$(RESET)"; \
	else \
		echo "$(GRAY)[" "$(RED)Error$(GRAY)" "] | $(RESET)An error occurred while creating checker."; \
		make fclean; \
		echo "$(GRAY)[" "$(RED)Error$(GRAY)" "] | $(RESET)All objects Cleaned."; \
	fi

$(LIBFT):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling libft..."
	@make -sC $(LIBFT_DIRECTORY) > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] | Libft ready!"

$(OBJECTS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@ || (rm -rf $(OBJECTS_DIRECTORY) && exit 1)

$(OBJECTS_DIRECTORY):
	@echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] | Creating objects...$(RESET)"
	@mkdir -p $(OBJECTS_DIRECTORY)

clean:
	@echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] | Removing object files...$(RESET)"
	@rm -rf $(OBJECTS_DIRECTORY)
	@make -sC $(LIBFT_DIRECTORY) clean > /dev/null 2>&1
	@echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] | Object files removed.$(RESET)"

fclean: clean
	@echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] | Removing binary files...$(RESET)"
	@rm -rf $(NAME)
	@make -sC $(LIBFT_DIRECTORY) fclean > /dev/null 2>&1
	@echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] | Binary file removed.$(RESET)"

norm:
	@echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] | Norminetting...$(GRAY)"
	@if norminette srcs/ | grep -q "Error!" ; then \
	    echo "$(RESET)[" "$(RED)!!$(RESET)" "] | Norminette found errors."; \
	    norminette srcs/ | awk '/Error!/ {print "[ " "$(RED)!!$(RESET)" " ] | " $$0}'; \
	else \
	    echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] | Norminette passed!"; \
	fi

re: fclean
	clear && make -s

run: re
	

run_extra: re
	make -sC Checker

run_die_test: re
	make -C Checker

val:re
	valgrind ./$(NAME) 28 59 70 45 19 55 24 96 32 18 49 9 69 25 37 83 33 35 47 31 48 90 64 11 95 71 68 98 86 10 13 3 54 7 8 88 46 52 65 21 66 5 22 76 30 1 89 34 99 2 62 91 26 38 67 94 93 16 73 36 42 79 75 23 80 58 53 14 15 97 40 81 27 20 44 6 61 29 60 56 100 87 77 74 92 63 85 41 12 51 78 84 4 43 50 57 17 39 82 72

val_full:re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) arg1 arg2 arg3

.PHONY: all clean fclean re
