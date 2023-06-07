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

// if the user introduz just the numbers | main
void	auto_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		smallest;

	sort(stack_a, stack_b);
	smallest = nr_movs(find_pos(*stack_a,
				find_smallest(*stack_a)), ft_lstsize(*stack_a));
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
			&& check_order_ok(stack_a) == 0)
			auto_sort(&stack_a, &stack_b);
		free(commands);
		while (stack_a != NULL)
			pop(&stack_a);
		while (stack_b != NULL)
			pop(&stack_b);
	}
	return (0);
}
