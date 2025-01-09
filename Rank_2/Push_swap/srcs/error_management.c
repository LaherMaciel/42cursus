/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:39:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/16 16:21:04 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check if a given value is present in the linked list.
 *
 * This function iterates through the linked list starting from the head,
 * checking if the specified value 'num' is present in any of the nodes.
 *
 * @param t_stack* head - Pointer to the head of the linked list.
 * @param int num - The value to check for in the linked list.
 *
 * @return int - Returns 0 if the value is found; otherwise, returns 1.
 */
int	contains_this_values(t_stack *head, int num)
{
	t_stack	*stack;

	stack = head;
	while (stack)
	{
		if (num == stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 * @brief Check if the linked list contains any duplicate values.
 *
 * This function iterates through the linked list, comparing each node's content
 * with the content of all subsequent nodes. If any duplicate values are found,
 * the function returns 1; otherwise, it returns 0.
 *
 * @param t_stack* head - Pointer to the head of the linked list.
 *
 * @return int - Returns 1 if duplicate values are found; otherwise, returns 0.
 */
int	contains_duplicate_values(t_stack *head)
{
	t_stack	*current1;
	t_stack	*current2;

	current1 = head;
	current2 = NULL;
	while (current1 != NULL)
	{
		current2 = current1->next;
		while (current2 != NULL)
		{
			if (current1->content == current2->content)
				return (1);
			current2 = current2->next;
		}
		current1 = current1->next;
	}
	return (0);
}

/**
 * @brief Check if the linked list is in ascending order.
 *
 * This function iterates through the linked list, checking if each node's
 * content is less than or equal to the content of the next node. If any
 * out-of-order elements are found, the function returns 1; otherwise, it
 * returns 0.
 *
 * @param t_stack* stack - Pointer to the head of the linked list.
 *
 * @return int - Returns 0 if the linked list is in ascending order; otherwise,
 * returns 1.
 */
int	check_order_ok(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/* int	check_order_ok_mid_sort(t_stack *stack)
{
	int	smallest;
	int	biggest;
	int	cont;

	smallest = find_smallest(stack);
	biggest = find_biggest(stack);
	cont = 0;
	if (stack == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
	
			return (1);
		stack = stack->next;
	}
	return (0);
}
 */
/**
 * @brief Check if all elements in the array of strings are valid integers.
 *
 * This function iterates through each element in the array of strings, checking
 * if every character is a digit. If any element contains non-digit characters,
 * the function returns 1; otherwise, it returns 0.
 *
 * @param char* argv[] - Array of strings to be checked.
 *
 * @return int - Returns 0 if all elements are valid integers; otherwise,
 * returns 1.
 */
int	input_ok(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
	}
	return (0);
}

/**
 * @brief Check for errors in the stack and commands.
 *
 * This function checks for various error conditions, including an empty stack,
 * non-empty commands, and the presence of duplicate values in the stack. If any
 * error is detected, it prints an error message and returns NULL; otherwise, it
 * returns "ok" if the stack size is bigger than 2.
 *
 * @param t_stack* stack - Pointer to the head of the stack.
 * @param char* commands - String representing commands (should be NULL).
 *
 * @return char* - Returns "ok" if the stack size is bigger than 2 and no other
 * errors are detected; otherwise, returns NULL.
 */
char	*error_check(t_stack *stack, char	*commands)
{
	if (stack == NULL || commands != NULL
		|| (contains_duplicate_values(stack) == 1))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	if (ft_lstsize_rem(stack) < 2)
		return (NULL);
	return ("ok");
}
