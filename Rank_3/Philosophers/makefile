NAME = philo

HEADER_LIST = philo.h
HEADER_DIRECTORY = srcs/
HEADERS = $(addprefix $(HEADER_DIRECTORY), $(HEADER_LIST))

SRCS_LIST = main.c utils.c philo_struct_handler.c printinfo.c table_struct_handler.c \
			rotine_helpers.c my_rotine.c
SRCS_DIRECTORY =
SRC = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

OBJECT_LIST = $(SRCS_LIST:.c=.o)
OBJECTS_DIRECTORY = objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_LIST))

CC = cc
CFLAGS = -g -Wall -Werror -Wextra #-fsanitize=address

INCLUDES = -I./srcs -I./libft/


# COLORS
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
RESET   = \033[0m

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@if $(CC) $(CFLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME); \
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

clean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing object files...$(RESET)"
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean: clean
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing binary files...$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(MLX)
	@rm -rf .norminette.log
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

run1: $(NAME)
	./$(NAME) 1 100 100 100

run11: $(NAME)
	./$(NAME) 1 100 100 100 1

run3: $(NAME)
	./$(NAME)  3 200 200 200

run33: $(NAME)
	./$(NAME)  3 200 200 200 3

val1: $(NAME)
	valgrind ./$(NAME) 1 100 100 100

val11: $(NAME)
	valgrind ./$(NAME) 1 100 100 100 10

val2: $(NAME)
	valgrind ./$(NAME) 2 100 100 100

val22: $(NAME)
	valgrind ./$(NAME) 2 100 100 100 10

val3: $(NAME)
	valgrind ./$(NAME)  3 200 200 200

val33: $(NAME)
	valgrind ./$(NAME)  3 200 200 200 5

val5: $(NAME)
	valgrind ./$(NAME)  5 200 200 200

val55: $(NAME)
	valgrind ./$(NAME)  5 200 200 200 5

val6: $(NAME)
	valgrind ./$(NAME)  6 200 200 200

val66: $(NAME)
	valgrind ./$(NAME)  6 200 200 200 6

.PHONY: all clean fclean re