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

NAME = push_swap

HEADER_LIST = push_swap.h
HEADER_DIRECTORY = srcs/
HEADERS = $(addprefix $(HEADER_DIRECTORY), $(HEADER_LIST))

SRCS_LIST = main.c error_management_bonus.c error_management.c errors_bonus.c \
find.c find2.c moviments.c moviments2.c p_decisions.c sort.c sort_conditions.c \
stack_work.c stack_work2.c ft_lstsize_rem.c ft_lstnew_rem.c sorters.c sort2.c\
ft_atoi_push.c sort3.c
SRCS_DIRECTORY = srcs/
SRC = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

LIBFT_DIRECTORY = libft/
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
		echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] Objects ready!$(RESET)"; \
		make norm -s; \
		echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] $(NAME) created!$(RESET)"; \
	else \
		echo "$(GRAY)[" "$(RED)Error$(GRAY)" "] $(RESET)An error occurred while creating push_swap."; \
		make fclean; \
		echo "$(GRAY)[" "$(RED)Error$(GRAY)" "] $(RESET)All objects Cleaned."; \
	fi

$(LIBFT):
	@echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] Compiling libft...$(RESET)"
	@make -sC $(LIBFT_DIRECTORY) > /dev/null 2>&1
	@echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] Libft ready!$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@ || (rm -rf $(OBJECTS_DIRECTORY) && exit 1)

$(OBJECTS_DIRECTORY):
	@echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] Creating objects...$(RESET)"
	@mkdir -p $(OBJECTS_DIRECTORY)

bonus:
	@echo "[" "$(YELLOW)..$(RESET)" "] Compiling Checker..."
	@make -sC Checker/ > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] Checker ready!"


clean:
	@echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] Removing object files...$(RESET)"
	@rm -rf $(OBJECTS_DIRECTORY)
	@make -sC $(LIBFT_DIRECTORY) clean > /dev/null 2>&1
	@make -sC Checker clean > /dev/null 2>&1
	@echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] Object files removed.$(RESET)"

fclean: clean
	@echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] Removing binary files...$(RESET)"
	@rm -rf $(NAME)
	@make -sC $(LIBFT_DIRECTORY) fclean > /dev/null 2>&1
	@make -sC Checker fclean > /dev/null 2>&1
	@$(RM) Push-Swap-Tester/push_swap > /dev/null 2>&1
	@echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] Binary file removed.$(RESET)"

norm:
	@echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] Norminetting...$(GRAY)"
	@if norminette srcs/ | grep -q "Error!" ; then \
	    echo "$(RESET)[" "$(RED)!!$(RESET)" "] Norminette found errors."; \
	    norminette srcs/ | awk '/Error!/ {print "[ " "$(RED)!!$(RESET)" " ] " $$0}'; \
	else \
	    echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] Norminette passed!"; \
	fi

install_visualizer:
	@if [ ! -d push_swap_visualizer ]; then \
		echo "$(RESET)[" "$(YELLOW)..$(RESET)" "] Cloning push_swap_visualizer...$(RESET)"; \
		git clone https://github.com/o-reo/push_swap_visualizer.git > /dev/null 2>&1; \
		if [ -d push_swap_visualizer ]; then \
			echo "$(RESET)[" "$(GREEN)OK$(RESET)" "] push_swap_visualizer Cloned Successfully!$(RESET)"; \
		else \
			echo "$(RESET)[" "$(RED)Error$(RESET)" "] $(RED)Failed to Clone push_swap_visualizer!$(RESET)"; \
			exit 1; \
		fi \
	else \
		echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] push_swap_visualizer Already Cloned!$(RESET)"; \
	fi

	@if [ ! -d push_swap_visualizer/build ]; then \
		echo "$(RESET)[" "$(YELLOW)..$(RESET)" "] Creating build Folder...$(RESET)"; \
		mkdir -p push_swap_visualizer/build; \
		if [ -d push_swap_visualizer/build ]; then \
			echo "$(RESET)[" "$(GREEN)OK$(RESET)" "] build Folder Created!$(RESET)"; \
		else \
			echo "$(RESET)[" "$(RED)Error$(RESET)" "] Failed to Create build Folder!$(RESET)"; \
			exit 1; \
		fi \
	else \
		echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] build Folder Already Exists!$(RESET)"; \
	fi

	echo "$(RESET)[" "$(YELLOW)..$(RESET)" "] Executing cmake...$(RESET)"; \
	cmake -S push_swap_visualizer -B push_swap_visualizer/build > /dev/null 2>&1; \
	if [ -d push_swap_visualizer/build/CMakeFiles ]; then \
		echo "$(RESET)[" "$(GREEN)OK$(RESET)" "] cmake Executed Successfully!$(RESET)"; \
	else \
		echo "$(RESET)[" "$(RED)Error$(RESET)" "] cmake Failed!$(RESET)"; \
		exit 1; \
	fi \

	echo "$(RESET)[" "$(YELLOW)..$(RESET)" "] Setting up push_swap_visualizer...$(RESET)"; \
	make -s -C push_swap_visualizer/build


install_tester:
	git clone https://github.com/gemartin99/Push-Swap-Tester.git
	sudo apt-get install ruby -y

re: fclean
	clear && make -s

run_visualizer: $(NAME)
	@if [ -x push_swap_visualizer/build/bin/visualizer ]; then \
		echo "$(GRAY)[" "$(GRAY)..$(GRAY)" "] Running push_swap_visualizer!$(RESET)"; \
	else \
		echo "$(RESET)[" "$(YELLOW)!!$(RESET)" "] Installing push_swap_visualizer...$(RESET)"; \
		$(MAKE) -s install_visualizer; \
		echo "$(RESET)[" "$(GREEN)OK$(RESET)" "] push_swap_visualizer Installed!$(RESET)"; \
	fi
	@cd push_swap_visualizer/build && ./bin/visualizer;

run_tester: $(NAME)
	@if [ ! -d Push-Swap-Tester ]; then \
		echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] Installing Push-Swap-Tester...$(RESET)"; \
		$(MAKE) install_tester; \
		echo "$(GRAY)[" "$(GREEN)OK$(GRAY)" "] Push-Swap-Tester Installed!$(RESET)"; \
	else \
		echo "$(GRAY)[" "$(YELLOW)..$(GRAY)" "] Running Push-Swap-Tester!$(RESET)"; \
	fi; \
	@cp push_swap /mnt/c/Users/ASUS/OneDrive/Documents/INFORMATICA/My_projects-1/42_projects/Rank_2/Push_swap/Push-Swap-Tester; \
	@cd Push-Swap-Tester/ && bash push_swap_test_linux.sh 100 100;

run_checker: $(NAME)
	@make -sC Checker
	@ARG="28 59 70 45 19"; ./push_swap $$ARG | ./Checker/checker $$ARG

run: $(NAME)
	./$(NAME) 28 59 70 45 19 55 24 96 32 18 49 9 69 25 37 83 33 35 47 31 48 90 64 11

val:re
	valgrind ./$(NAME) 28 59 70 45 19 55 24 96 32 18 49 9 69 25 37 83 33 35 47 31 48 90 64 11 95 71 68 98 86 10 13 3 54 7 8 88 46 52 65 21 66 5 22 76 30 1 89 34 99 2 62 91 26 38 67 94 93 16 73 36 42 79 75 23 80 58 53 14 15 97 40 81 27 20 44 6 61 29 60 56 100 87 77 74 92 63 85 41 12 51 78 84 4 43 50 57 17 39 82 72 

val_full: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) 28 59 70 45 19 55 24 96 32 18 49 9 69 25 37 83 33 35 47 31 48 90 64 11 95 71 68 98 86 10 13 3 54 7 8 88 46 52 65 21 66 5 22 76 30 1 89 34 99 2 62 91 26 38 67 94 93 16 73 36 42 79 75 23 80 58 53 14 15 97 40 81 27 20 44 6 61 29 60 56 100 87 77 74 92 63 85 41 12 51 78 84 4 43 50 57 17 39 82 72 

.PHONY: all clean fclean re
