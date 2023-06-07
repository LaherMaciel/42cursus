/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:39:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/10 22:03:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	commands_check(char *str)
{
	int		i;
	char	**valid_commands;

	valid_commands = valid_strings();
	i = -1;
	while (++i < 11)
	{
		if (ft_strlen(str) < 2)
			break ;
		else if (ft_strncmp(str, valid_commands[i], ft_strlen(str)) == 0)
		{
			free(valid_commands);
			return (1);
		}
	}
	i = -1;
	free(valid_commands);
	return (0);
}

char	*check_commands_cut(char **val)
{
	int	i;

	i = -1;
	while (val[++i] != NULL)
	{
		commands_check_aux2(val, i);
		if (commands_check(val[i]) == 0)
			return (NULL);
	}
	return ("ok");
}

char	*check_commands_cut2(char **val, char *commands)
{
	int		i;
	char	*temp;

	i = -1;
	if (check_commands_cut(val) == NULL)
	{
		free(commands);
		return (NULL);
	}
	while (val[++i])
	{
		if (commands == NULL)
			commands = ft_strjoin(val[0], "  ");
		else
		{
			temp = ft_strjoin(commands, val[i]);
			free(commands);
			commands = ft_strjoin(temp, "  ");
			free(temp);
		}
	}
	return (commands);
}

char	*check_commands(char *argv[], int stacksize)
{
	char	**val;
	char	*commands;
	int		i;

	commands = NULL;
	while (argv[++stacksize] != NULL)
	{
		i = -1;
		val = ft_split(argv[stacksize], ' ');
		commands = check_commands_cut2(val, commands);
		while (val[++i])
			free(val[i]);
		free(val);
		if (commands == NULL)
			return (NULL);
	}
	return (commands);
}

char	*error_check_bonus(int argc, char *argv[], t_stack *stack)
{
	char	*commands;

	commands = NULL;
	if (stack == NULL || (contains_duplicate_values(stack) == 0))
	{
		ft_printf("Error\n");
		return (NULL);
	}
	if (argc == ft_lstsize(stack) && check_order_ok(stack) != 0)
		return (NULL);
	if (argc == ft_lstsize(stack) && check_order_ok(stack) == 0)
		return ("xa");
	if (ft_lstsize(stack) < argc)
		commands = check_commands(argv, ft_lstsize(stack));
	if (commands == NULL)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	return (commands);
}

/*
	if (argc == ft_lstsize(stack) && check_order_ok(stack) != 0)
		return ("ex");
	if (argc == ft_lstsize(stack) && check_order_ok(stack) != 0)
	{
		ft_printf("Error");
		return (NULL);
	}
*/