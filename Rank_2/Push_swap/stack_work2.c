/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_work2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:52:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/25 17:09:25 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks conditions related to individual characters in the value
 * string. Checks if the current character in the value string is valid.
 *
 * @param vals The value string to be checked.
 * @param commands The command string (unused in this function).
 * @param skip The current state of skipping (2 if skipping, 0 if invalid, 1
 * otherwise).
 * @param stack The stack (unused in this function).
 * @return int Returns the updated skip state.
 */
int	store_cut4(char *vals, char *commands, int skip, t_stack *stack)
{
	int	j;

	j = 0;
	if ((vals[j] == '-' || vals[j] == '+')
		&& ft_isdigit(vals[j + 1] != 1))
		return (0);
	if (stack != NULL && ft_isdigit(vals[j]) == 0
		&& ((vals[j] != '-' || vals[j] != '+')
			&& ft_isdigit(vals[j + 1] != 1)))
		return (0);
	if (ft_isdigit(vals[j]) == 0 && ((vals[j] != '-' || vals[j] != '+')
			&& ft_isdigit(vals[j + 1] != 1)) && skip == 1)
		return (0);
	if (ft_isdigit(vals[j]) == 1 && ((vals[j] == '-' || vals[j] == '+')
			&& ft_isdigit(vals[j + 1] == 1))
		&& commands != NULL && skip == 2)
		return (0);
	if (ft_isdigit(vals[j]) == 1 && (vals[j + 1] == '-' || vals[j + 1] == '+'))
		return (0);
	return (skip);
}

/**
 * @brief Iterates through characters in the value string and checks conditions
 * for validity.
 *
 * @param vals The value string to be checked.
 * @param commands The command string (unused in this function).
 * @param skip The current state of skipping (2 if skipping, 0 if invalid, 1
 * otherwise).
 * @param stack The stack (unused in this function).
 * @return int Returns the updated skip state.
 */
int	store_cut3(char *vals, char *commands, int skip, t_stack *stack)
{
	int	j;

	j = -1;
	while (vals[++j])
	{
		skip = store_cut4(vals, commands, skip, stack);
		if (skip == 0)
			return (0);
		if (ft_isdigit(vals[j]) == 0 && (vals[j] != '-'
				&& vals[j] != '+') && skip == 1)
			return (0);
		if ((vals[j] == '-' || vals[j] == '+')
			&& (vals[j + 1] == '-' || vals[j + 1] == '+'))
			return (0);
		if (ft_isdigit(vals[j]) == 1 && (ft_isdigit(vals[j + 1] == 0)))
			return (0);
		if (ft_isdigit(vals[j]) == 1 || ((vals[j] == '-' || vals[j] == '+')
				&& ft_isdigit(vals[j + 1] == 1)))
			skip = 1;
	}
	return (skip);
}

/**
 * @brief Parses and pushes values onto the stack based on input conditions.
 *
 * @param stack A pointer to the stack.
 * @param vals The array of strings to be parsed.
 * @param commands The command string.
 * @param i The current index in the array of strings.
 * @return int Returns the updated skip state.
 */
int	store_cut2(t_stack **stack, char **vals, char *commands, int i)
{
	long	skip;
	long	parsed_val;

	commands_check_aux2(vals, i);
	skip = store_cut3(vals[i], commands, 2, *stack);
	if (skip == 1)
	{
		parsed_val = ft_atoi(vals[i]);
		if (parsed_val > INT_MAX || parsed_val < INT_MIN)
			return (0);
		push(stack, parsed_val);
	}
	else if (skip == 0)
		return (0);
	return (skip);
}

/**
 * @brief Iterates through input values and builds a command string.
 *
 * @param stack A pointer to the stack.
 * @param vals The array of strings to be processed.
 * @param commands The command string.
 * @param i The current index in the array of strings.
 * @return char* Returns the command string or NULL if any invalid condition is
 * encountered.
 */
char	*store_cut(t_stack **stack, char **vals, char *commands, int i)
{
	int		skip;
	char	*temp;

	while (--i >= 0)
	{
		skip = store_cut2(stack, vals, commands, i);
		if (skip == 2)
		{
			if (commands == NULL)
				commands = ft_strjoin("  ", vals[i]);
			else
			{
				temp = ft_strjoin(vals[i], commands);
				if (commands[0] != 'o' && commands[1] != 'k')
					free(commands);
				commands = ft_strjoin("  ", temp);
				free(temp);
			}
		}
		else if (skip == 0)
			return (NULL);
	}
	if (commands == NULL)
		return ("ok");
	return (commands);
}

/**
 * @brief Processes command-line arguments and builds a stack based on valid
 * input values.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @param commands The command string.
 * @param stack A pointer to the stack.
 * @return t_stack* Returns the resulting stack or NULL if any invalid condition
 * is encountered.
 */
t_stack	*store_stack(int argc, char *argv[], char **commands, t_stack *stack)
{
	char	**vals;
	int		i;

	while (--argc > 0)
	{
		vals = ft_split(argv[argc], ' ');
		i = 0;
		while (vals[i])
			i++;
		*commands = store_cut(&stack, vals, *commands, i);
		i = -1;
		if (*commands == NULL)
		{
			while (vals[++i])
				free(vals[i]);
			free(vals);
			while (stack != NULL)
				pop(&stack);
			return (NULL);
		}
		while (vals[++i])
			free(vals[i]);
		free(vals);
	}
	return (stack);
}
