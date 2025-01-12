# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 19:50:00 by lwencesl          #+#    #+#              #
#    Updated: 2023/10/02 16:25:04 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_DIRECTORY = libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)libft.h
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADER_LIST = pipex.h
HEADER_DIRECTORY = srcs/
HEADERS = $(addprefix $(HEADER_DIRECTORY), $(HEADER_LIST))

SRCS_LIST = main.c my_prints.c utils.c
SRCS_DIRECTORY = srcs/
SRC = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

OBJECT_LIST = $(SRCS_LIST:.c=.o)
OBJECTS_DIRECTORY = objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_LIST))

CC = cc
CFLAGS = -g -Wall -Werror -Wextra #-fsanitize=address

LIBS = -L$(LIBFT_DIRECTORY) -lft
INCLUDES = -I./srcs -I./libft/


# COLORS
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
RESET   = \033[0m

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@if $(CC) $(CFLAGS) $(OBJECTS) $(INCLUDES) $(LIBS) -o $(NAME); \
	then \
		make norm -s; \
		echo "[" "$(GREEN)OK$(RESET)" "] | $(NAME) created!"; \
	else \
		echo "[" "$(RED)Error$(RESET)" "] | An error occurred while creating pipex."; \
		make fclean; \
		echo "[" "$(RED)Error$(RESET)" "] | All objects Cleaned."; \
	fi

$(OBJECTS_DIRECTORY):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Creating objects..."
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Objects ready!"

$(OBJECTS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling libft..."
	@make -sC $(LIBFT_DIRECTORY)  > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] | Libft ready!"

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
	@if norminette srcs/ libft/ images/ > .norminette.log ; then \
	    if grep -q "Error!" .norminette.log; then \
	        echo "[" "$(RED)!!$(RESET)" "] | Norminette found errors.$(RESET)"; \
	        grep "Error!" .norminette.log | awk '{print "[ " "$(RED)!!$(RESET)" " ] | " $$0}'; \
	    else \
	        echo "[" "$(GREEN)OK$(RESET)" "] | Norminette passed!"; \
	    fi; \
	else \
	    echo "[" "$(RED)XX$(RESET)" "] | Norminette Error!"; \
		norminette srcs/ libft/ images/ | awk '/Error!/ {print "[ " "$(RED)!!$(RESET)" " ] | " $$0}'; \
	fi

re: fclean
	clear && make -s

noinfile: $(NAME)
	./$(NAME) infile "ls -l" "wc -l" /dev/stdout

noinfile_grep: $(NAME)
	./$(NAME) infile "grep a1" "wc -w" outfile

noinfilecat: $(NAME)
	./$(NAME) infile "cat" "grep hello" "wc -l" /dev/stdout

run: $(NAME)
	./$(NAME) infile.txt "ls -l" "wc -l" /dev/stdout

run_grep: $(NAME)
	./$(NAME) infile.txt "grep a1" "wc -w" /dev/stdout

run_cat: $(NAME)
	./$(NAME) infile.txt "cat" "grep hello" "wc -l" /dev/stdout

run_cmderror: $(NAME)
	./$(NAME) infile.txt "l -l" "wc -l" /dev/stdout

run_cmderror_grep: $(NAME)
	./$(NAME) infile.txt "grep a1" "wh -w" /dev/stdout

run_cmderror_cat: $(NAME)
	./$(NAME) infile.txt "catt" "grep hello" "wc -w" /dev/stdout

val: $(NAME)
	valgrind ./$(NAME) infile.txt "ls -l" "wc -l" /dev/stdout

val2_noinfile: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --track-origins=yes -s ./$(NAME) infile.txt "ls -l" "wc -l" /dev/stdout

val2_noinfile_grep: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --track-origins=yes -s ./$(NAME) infile.txt "grep a1" "wc -w" /dev/stdout

val2_noinfile_cat: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --track-origins=yes -s ./$(NAME) infile.txt "cat" "grep hello" "wc -w" /dev/stdout

val2_cmderror: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --track-origins=yes -s ./$(NAME) infile.txt "l -l" "wc -l" /dev/stdout

val2_cmderror_grep: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --track-origins=yes -s ./$(NAME) infile.txt "grep a1" "wh -w" /dev/stdout

val2_cmderror_cat: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --track-origins=yes -s ./$(NAME) infile.txt "catt" "grep hello" "wc -w" /dev/stdout

val2: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --track-origins=yes -s ./$(NAME) infile.txt "ls -l" "wc -l" /dev/stdout

val2_grep: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --track-origins=yes -s ./$(NAME) infile.txt "grep a1" "wc -w" /dev/stdout

val2_cat: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --track-origins=yes -s ./$(NAME) infile.txt "cat" "grep hello" "wc -l" /dev/stdout

val_full: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) infile.txt "grep a1" "wc -l" /dev/stdout

val_full_errocommand: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) infile.txt "grp a1" "wc -l" /dev/stdout

.PHONY: all clean fclean re