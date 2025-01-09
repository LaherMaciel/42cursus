/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:43:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/24 19:24:13 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*commands;

	if (argc > 1)
	{
		commands = NULL;
		stack_a = store_stack(argc, argv, &commands, NULL);
		stack_b = NULL;
		if (commands != NULL
			&& ft_strncmp(commands, "ok", ft_strlen(commands)) == 0)
			commands = NULL;
		commands = error_check_bonus((argc - 1), stack_a, commands);
		if (commands != NULL && commands[0] != 'x')
			inputed_commands(&stack_a, &stack_b, commands);
		else if (commands != NULL && commands[0] == 'x')
			proxy(&stack_a, &stack_b, -1);
		if ((commands != NULL && commands[0] != 'x'))
			free(commands);
		while (stack_a != NULL)
			pop(&stack_a);
		while (stack_b != NULL)
			pop(&stack_b);
	}
	return (0);
}
