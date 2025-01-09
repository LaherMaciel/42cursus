/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:39:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/27 12:52:14 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

char	*check_commands(char *comma)
{
	char	**val;
	char	*commands;
	int		i;

	commands = NULL;
	val = ft_split(comma, ' ');
	commands = check_commands_cut2(val, commands);
	i = -1;
	while (val[++i])
		free(val[i]);
	free(val);
	if (commands == NULL)
		return (NULL);
	return (commands);
}

char	*error_check_bonus2(int argc, t_stack *stack, char *comma)
{
	if (comma == NULL)
	{
		if (ft_lstsize_rem(stack) == 1 || (ft_lstsize_rem(stack) > 1
				&& check_order_ok(stack) != 0))
			return ("xpr");
		if (ft_lstsize_rem(stack) > 1 && check_order_ok(stack) == 0)
			return ("xpr");
		if (argc == 0)
			return ("xpr");
	}
	return ("ok");
}

char	*error_check_bonus(int argc, t_stack *stack, char *comma)
{
	char	*commands;

	if (argc != 0 && (stack == NULL || (contains_duplicate_values(stack) == 0)
			|| (ft_lstsize_rem(stack) == 1 && comma != NULL)))
	{
		ft_fdprintf(2, "Error\n");
		free(comma);
		return (NULL);
	}
	commands = error_check_bonus2(argc, stack, comma);
	if (commands == NULL
		|| ft_strncmp(commands, "ok", ft_strlen(commands)) != 0)
		return (commands);
	if (comma != NULL)
	{
		commands = check_commands(comma);
		free(comma);
		if (commands == NULL)
		{
			ft_fdprintf(2, "Error\n");
			return (NULL);
		}
	}
	return (commands);
}
