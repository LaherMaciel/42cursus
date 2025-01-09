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

/**
 * @brief Check if the given string corresponds to a valid command.
 *
 * This function compares the input string with a predefined list of valid
 * commands to determine if it is a valid command. Called by
 * `check_commands_cut()`
 *
 * @param char* str - The input string to be checked.
 *
 * @return int - Returns 1 if the string is a valid command, otherwise returns
 * 0.
 */
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
	free(valid_commands);
	return (0);
}

/**
 * @brief Process, sanitize, and verify if each string represents a valid
 * command.
 *
 * This function iterates through each string in the 'val' array, processing it
 * using `commands_check_aux2()` and then checking the processed strings with
 * `commands_check()`. If any of the processed strings is invalid, it returns
 * NULL; otherwise, it returns "ok".
 *
 * @param char** val - Array of strings representing commands.
 *
 * @return char* - Returns "ok" if all commands are valid; otherwise, returns
 * NULL
*/
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

/**
 * @brief Process and concatenate an array of strings representing commands.
 *
 * This function processes each string in the val array using
 * `check_commands_cut()` and then concatenates the processed strings to a
 * larger string, separated by spaces. If any of the processed strings is
 * invalid, it returns NULL; otherwise, it returns the concatenated string.
 *
 * @param char** val - Array of strings representing commands.
 * @param char* commands - Initial string to concatenate with processed strings.
 *
 * @return char* - Returns the concatenated string if all commands are valid,
 * otherwise returns NULL.
 */
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

/**
 * @brief Process and concatenate command-line arguments into a single string.
 *
 * This function processes each command-line argument by splitting it into
 * individual commands and then concatenates the processed strings into a single
 * string, separated by spaces. If any of the processed strings is invalid, it
 * returns NULL; otherwise, it returns the concatenated string.
 *
 * @param char* argv[] - Array of command-line arguments.
 * @param int stacksize - Starting index of command-line arguments to process.
 *
 * @return char* - Returns the concatenated string if all commands are valid,
 * otherwise returns NULL.
 */
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

/**
 * @brief Perform error checks on the command-line arguments and stack for
 * bonus.
 *
 * This function performs several error checks on the command-line arguments and
 * the state of the stack for bonus operations. It checks for the presence of a
 * stack, the absence of duplicate values, the order of the stack, and the
 * validity of commands. If any error is detected, it prints an error message
 * and returns NULL; otherwise, it returns the concatenated string of valid
 * commands.
 *
 * @param int argc - Number of command-line arguments.
 * @param char* argv[] - Array of command-line arguments.
 * @param t_stack* stack - Pointer to the head of the stack.
 *
 * @return char* - Returns the concatenated string of valid commands if all
 * checks pass, otherwise returns NULL.
 */
char	*error_check_bonus(int argc, char *argv[], t_stack *stack)
{
	char	*commands;

	commands = NULL;
	if (stack == NULL || (contains_duplicate_values(stack) == 0))
	{
		ft_printf("Error\n");
		return (NULL);
	}
	if (argc == ft_lstsize_rem(stack) && check_order_ok(stack) != 0)
		return (NULL);
	if (argc == ft_lstsize_rem(stack) && check_order_ok(stack) == 0)
		return ("xa");
	if (ft_lstsize_rem(stack) < argc)
		commands = check_commands(argv, ft_lstsize_rem(stack));
	if (commands == NULL)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	return (commands);
}
