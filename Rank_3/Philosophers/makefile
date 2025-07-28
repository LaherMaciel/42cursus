NAME = philo

HEADER_LIST = philo.h
HEADERS = $(HEADER_LIST)

SRCS_LIST = main.c utils.c philo_struct_handler.c printinfo.c table_struct_handler.c \
	rotine_helpers.c my_rotine.c rotine_utils.c main_utils.c main_utils2.c rotine_helpers2.c my_rotine_utils.c my_rotine_prints.c thread_handler.c monitoring.c
SRC = $(SRCS_LIST)

OBJECT_LIST = $(SRCS_LIST:.c=.o)
OBJECTS_DIRECTORY = objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_LIST))

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

INCLUDES = -I.

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : %.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	rm -rf $(NAME)

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

.PHONY: all clean fclean re