/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_run_modes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:01:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/27 13:56:26 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//check if the order of the list is ok
void	end_code(t_stack **stack_a, t_stack **stack_b, char *commands)
{
	if (commands != NULL && (check_order_ok(*stack_a) == 1) && *stack_b == NULL)
		ft_printf("\nOK\n");
	else if (commands != NULL)
		ft_printf("\nKO\n");
	free(commands);
}

//	Verify if the command is ok. If its ok it 
//executes it, if its not, return a error message.
int	user_sort(t_stack **stack_a, t_stack **stack_b, char *command)
{
	int		i;

	i = -1;
	while (command[++i])
	{
		if (ft_strncmp(command, "pa", 2) == 0 && stack_a == NULL)
			ft_printf("\n");
		if (ft_strncmp(command, "pb", 2) == 0 && stack_b == NULL)
			ft_printf("\n");
	}
	sorting(stack_a, stack_b, command);
	if (commands_check(command) == 0 && ft_strncmp(command, "exit", 4) != 0)
	{
		ft_fdprintf(2, "Error\n");
		return (0);
	}
	if (ft_strncmp(command, "exit", 4) == 0)
		return (2);
	return (1);
}

char	**the_split(char *commands)
{
	char	**vals;
	char	*comma;
	int		i;

	comma = check_commands(commands);
	if (comma == NULL)
	{
		ft_fdprintf(2, "Error\n");
		return (NULL);
	}
	free(comma);
	vals = ft_split(commands, ' ');
	if (ft_strlen(*vals) == ft_strlen(commands))
	{
		i = -1;
		while (vals[++i])
			free(vals[i]);
		free(vals);
		vals = ft_split(commands, '\n');
	}
	return (vals);
}

// if the user introduz the numbers and the commands | main
void	inputed_commands(t_stack **stack_a,
		t_stack **stack_b, char *command_list)
{
	char	**commands;
	int		returned;
	int		i;

	commands = ft_split(command_list, ' ');
	i = -1;
	while (commands[++i] != NULL)
	{
		returned = user_sort(stack_a, stack_b, commands[i]);
		free(commands[i]);
		if (returned == 2)
		{
			free(commands);
			return ;
		}
	}
	end_code(stack_a, stack_b, *commands);
	free(commands);
}
