/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:05:00 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/17 19:26:42 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check if there are duplicate values in the command-line arguments.
 *
 * This function checks for duplicate integer values in the array of
 * command-line arguments, ensuring that each value is unique.
 *
 * @param int argc - The number of command-line arguments.
 * @param char* argv[] - Array of command-line arguments.
 *
 * @return int - Returns 1 if all values are unique, otherwise returns 0.
 */
int	check_vals(int argc, char *argv[])
{
	int		i;
	int		j;
	size_t	val;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		val = ft_atoi(argv[i]);
		while (++j < argc)
			if (val == ft_atoi(argv[j]) && i != j)
				return (0);
	}
	return (1);
}

/**
 * @brief Check if the stack is sorted in ascending order.
 *
 * This function traverses the linked list representing a stack and checks if
 * each element is less than or equal to the next element, ensuring that the
 * stack is sorted in ascending order.
 *
 * @param t_stack* stack - Pointer to the head of the stack.
 *
 * @return int - Returns the index of the first unsorted element if any,
 * otherwise returns 0, indicating a sorted stack.
 */
int	check_stack(t_stack *stack)
{
	t_stack	*current;
	int		cont;

	current = stack;
	cont = 0;
	while (current)
	{
		if (current->content > current->next->content)
			return (cont);
		cont++;
		current = current->next;
	}
	return (0);
}

/**
 * @brief Get an array of valid command strings.
 *
 * This function allocates memory for an array of valid command strings. The
 * caller is responsible for freeing the allocated memory when done.
 *
 * @return char** - An array of valid command strings.
 */
char	**valid_strings(void)
{
	char	**commands;

	commands = (char **) malloc(11 * sizeof(char *));
	if (!commands)
		return (NULL);
	commands[0] = "ss";
	commands[1] = "sa";
	commands[2] = "sb";
	commands[3] = "pa";
	commands[4] = "pb";
	commands[5] = "rr";
	commands[6] = "ra";
	commands[7] = "rb";
	commands[8] = "rrr";
	commands[9] = "rra";
	commands[10] = "rrb";
	return (commands);
}

/**
 * @brief Process and sanitize a string in the val array.
 *
 * This function modifies the string at val[i] to ensure it is properly
 * formatted. It removes unnecessary characters such as '[' or ']' and updates
 * the val array accordingly. If the string cannot be processed, it sets out to
 * 1. Its called by `commands_check_aux2()`.
 *
 * @param char** val - Array of strings.
 * @param int i - Index of the string to process.
 * @param int out - Output flag indicating success (0) or failure (1).
 *
 * @return int - Updated output flag.
 */
int	commands_check_aux3(char **val, int i, int out)
{
	char	*temp;	

	temp = val[i];
	if (ft_strchr(temp, '[')
		&& (ft_strchr(temp, ']') || ft_strchr(temp, ',')))
		val[i] = ft_substr(temp, 1, ft_strlen(temp) - 2);
	else if (ft_strchr(temp, ']') || ft_strchr(temp, ','))
		val[i] = ft_substr(temp, 0, ft_strlen(temp) - 1);
	else if (ft_strchr(temp, '[') || ft_strchr(temp, ','))
		val[i] = ft_substr(temp, 1, ft_strlen(temp) - 1);
	else
		out = 1;
	if (ft_strncmp(temp, val[i], ft_strlen(temp)) != 0)
		free(temp);
	return (out);
}

/**
 * @brief Process and sanitize a string in the val array until a valid format is
 * achieved.
 *
 * This function continuously processes and modifies the string at val[i] until
 * a valid format is achieved. It calls `commands_check_aux3()` for initial
 * processing and handles additional cases such as removing quotation marks.
 *
 * @param char** val - Array of strings.
 * @param int i - Index of the string to process.
 *
 * @return char* - Processed and sanitized string.
 */
char	*commands_check_aux2(char **val, int i)
{
	char	*temp;
	int		out;

	out = 0;
	while (out == 0)
	{
		temp = val[i];
		if (commands_check_aux3(val, i, out) == 0)
			temp = val[i];
		else if (temp[0] == '"' && temp[ft_strlen(temp)] == '"')
			val[i] = ft_substr(temp, 1, ft_strlen(temp) - 2);
		else if (temp[0] == '"')
			val[i] = ft_substr(temp, 1, ft_strlen(temp) - 1);
		else if (temp[ft_strlen(temp) - 1] == '"')
			val[i] = ft_substr(temp, 0, ft_strlen(temp) - 1);
		else
			out = 1;
		if (ft_strncmp(temp, val[i], ft_strlen(temp)) != 0)
			free(temp);
	}
	return (val[i]);
}
