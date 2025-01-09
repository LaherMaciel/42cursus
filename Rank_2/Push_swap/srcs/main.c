/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:29 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/06 10:12:47 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief   Automatically sorts the given stack (stack_a). This function is
 *  called by the `main()` function and internally invokes the `sort()` function
 *  from the `sort.c` file for the initial sorting process. After sorting, it
 *  uses the `while()` loop to move the smallest number to the top of the stack.
 *
 * @param   stack_a     Pointer to the first stack to be sorted.
 * @param   stack_b     Pointer to the second stack (not used in this function).
 */
void	auto_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		smallest;

	sort(stack_a, stack_b);
	smallest = nr_movs(find_pos(*stack_a,
				find_smallest(*stack_a)), ft_lstsize_rem(*stack_a));
	while (smallest != 0)
	{
		if (smallest > 0)
		{
			ft_reverse_rotate(stack_a, 'a');
			smallest--;
		}
		else if (smallest < 0)
		{
			ft_rotate(stack_a, 'a');
			smallest++;
		}
	}
}

/**
 * @brief   Main function for a program.
 * 
 * @param   argc    The number of command-line arguments.
 * @param   argv    An array of strings representing the command-line arguments.
 * 
 * @return  Returns 0 upon successful execution.
 */
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*commands;

	if (argc > 1)
	{
		commands = NULL;
		stack_b = NULL;
		stack_a = store_stack(argc, argv, &commands, NULL);
		if (commands != NULL
			&& ft_strncmp(commands, "ok", ft_strlen(commands)) == 0)
			commands = NULL;
		if (error_check(stack_a, commands) != NULL
			&& check_order_ok(stack_a) == 1)
			auto_sort(&stack_a, &stack_b);
		free(commands);
		while (stack_a != NULL)
			pop(&stack_a);
		while (stack_b != NULL)
			pop(&stack_b);
	}
	return (0);
}
