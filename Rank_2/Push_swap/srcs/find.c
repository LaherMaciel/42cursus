/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:17:38 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/02 21:23:51 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Find and return the closest value in the stack that is smaller than
 * the given value.
 *
 * This function searches the stack for a value smaller than the specified value
 * and returns the closest smaller value. If the stack is empty, the function
 * returns 0.
 *
 * @param t_stack* head - The head of the stack where the function must search.
 * @param int val - Find a value smaller than this.
 * @param int smallest - The current smallest value found during the search.
 *
 * @return int - The smallest value found or 0 if the stack is empty.
 */
int	find_smaller_then(t_stack *head, int val, int smallest)
{
	t_stack	*current;
	int		new_smallest;

	if (head == NULL)
		return (0);
	current = head;
	new_smallest = smallest;
	while (current)
	{
		if (current->content < val && current->content > new_smallest)
			new_smallest = current->content;
		current = current->next;
	}
	return (new_smallest);
}

/**
 * @brief Find and return the smallest value in the stack.
 *
 * This function searches the stack for the smallest value and returns it. If
 * the stack is empty, the function returns 0.
 *
 * @param t_stack* head - The head of the stack where the function must search.
 *
 * @return int - The smallest value found or 0 if the stack is empty.
 */
int	find_smallest(t_stack *head)
{
	int	val;

	if (head == NULL)
		return (0);
	val = head->content;
	while (head)
	{
		if (head->content < val)
			val = head->content;
		head = head->next;
	}
	return (val);
}

/**
 * @brief Find and return the closest value in the stack that is bigger than the
 * given value.
 *
 * This function searches the stack for a value bigger than the specified value
 * and returns the closest bigger value. If the stack is empty, the function
 * returns 0.
 *
 * @param t_stack* head - The head of the stack where the function must search.
 * @param int val - Find a value bigger than this.
 * @param int biggest - The current biggest value found during the search.
 *
 * @return int - The biggest value found or 0 if the stack is empty.
 */
int	find_bigger_then(t_stack *head, int val, int biggest)
{
	t_stack	*current;
	int		new_bigger;

	if (head == NULL)
		return (0);
	current = head;
	new_bigger = biggest;
	while (current)
	{
		if (current->content > val && current->content < new_bigger)
			new_bigger = current->content;
		current = current->next;
	}
	return (new_bigger);
}

/**
 * @brief Find and return the largest value in the stack.
 *
 * This function searches the stack for the largest value and returns it. If the
 * stack is empty, the function returns 0.
 *
 * @param t_stack* head - The head of the stack where the function must search.
 *
 * @return int - The largest value found or 0 if the stack is empty.
 */
int	find_biggest(t_stack *head)
{
	t_stack	*current;
	int		val;

	if (head == NULL)
		return (0);
	current = head;
	val = current->content;
	while (current)
	{
		if (current->content > val)
			val = current->content;
		current = current->next;
	}
	return (val);
}

/**
 * @brief Find and return the position (index) of a specific value in the stack.
 *
 * This function searches the stack for a specific value and returns its
 * position (index) in the stack. If the value is not found or the stack is
 * empty, the function returns -1.
 *
 * @param t_stack* head - The head of the stack where the function must search.
 * @param int val - The value to find in the stack.
 *
 * @return int - The position (index) of the value in the stack or -1 if not
 * found.
 */
int	find_pos(t_stack *head, int val)
{
	t_stack	*current;
	int		cont;

	if (head == NULL)
		return (-1);
	cont = 0;
	current = head;
	while (current)
	{
		if (val == current->content)
			return (cont);
		cont++;
		current = current->next;
	}
	return (-1);
}
