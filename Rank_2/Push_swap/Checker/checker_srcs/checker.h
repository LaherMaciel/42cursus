/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:33:52 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/27 13:59:01 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

//# include "libft.h"

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include "../../libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

// Moviments moviments.c && moviments2.c
void	ft_swap(t_stack **head);
void	ft_swap_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_pass_to(t_stack **src, t_stack **dest);
void	ft_rotate(t_stack **stack);
void	ft_rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack);
void	ft_reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b);

//ERROR CHECKS error_managemant.c
int		contains_this_values(t_stack *head, int num);
int		contains_duplicate_values(t_stack *head);
int		check_vals(int argc, char *argv[]);
int		check_stack(t_stack *stack);
int		check_order_ok(t_stack *stack);

// ERROR_MANAGEMENT_BONUS.C
int		commands_check(char *str);
char	**valid_strings(void);
char	*error_check_bonus(int argc, t_stack *stack, char *comma);
char	*check_commands(char *comma);
char	*commands_check_aux2(char **val, int i);
int		commands_check(char *str);

// List manipulation stack_work.c
int		pop(t_stack **stack);
void	push(t_stack **stack, int data);
void	print_stack(t_stack *head);
t_stack	*store_stack(int argc, char *argv[], char **commands, t_stack *stack);

// all the find functions find.c && find2.c
int		find_smallest(t_stack *stack);
int		find_bigger_then(t_stack *head, int val, int biggest);
int		find_biggest(t_stack *stack);
int		find_pos(t_stack *head, int val);
int		find_val(t_stack *stack, int val);
int		find_media(t_stack *stack);
int		find_above_media(t_stack *stack, int cont1, int cont2);

// BONUS_RUN_MODE.C
void	inputed_commands(t_stack **stack_a,
			t_stack **stack_b, char *command_list);
void	proxy(t_stack **stack_a, t_stack **stack_b, int i);

void	sorting(t_stack **stack_a, t_stack **stack_b, char *id_1);

// libeft remixed function
int		ft_lstsize_rem(t_stack *lst);
t_stack	*ft_lstnew_rem(int content);

// Main
void	end_code(t_stack **stack_a, t_stack **stack_b, char *commands);

// visualizer
void	visualizer(t_stack **stack_a, t_stack **stack_b);
void	visualizer2(t_stack **stack_a, t_stack **stack_b);
void	p_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	ss_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	rr_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	rrr_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	print_tab(t_stack *stack_a, t_stack *stack_b);

size_t	ft_my_sizeof(const void *ptr);
size_t	ft_strchr_int(const char *str, int c);
int		ft_strstrlen(char **str_of_str);
char	**the_split(char *commands);
int		user_sort(t_stack **stack_a, t_stack **stack_b, char *command);
void	end_code(t_stack **stack_a, t_stack **stack_b, char *commands);

#endif