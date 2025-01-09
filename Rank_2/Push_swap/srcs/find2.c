/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:34:41 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/18 11:42:09 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the value at a specified position in a linked list.
 *
 * This function traverses a linked list represented by the t_stack structure
 * and finds the value at the specified position. The position can be positive
 * or negative, indicating the distance from the head or the end of the linked
 * list. If the position is out of bounds, the function returns 0.
 *
 * @param head A pointer to the head of the linked list (t_stack structure).
 * @param pos The position of the value to be found. Can be positive or
 * negative.
 * @return The value at the specified position, or 0 if the position is out of
 * bounds.
 */
int	find_val(t_stack *head, int pos)
{
	t_stack	*current;
	int		cont;

	if (head == NULL)
		return (0);
	if (pos < 0)
		pos = pos * (-1);
	else if (pos > 0)
		pos = ft_lstsize_rem(head) - pos;
	cont = 0;
	current = head;
	while (cont < pos)
	{
		current = current->next;
		if (current == NULL)
			return (0);
		cont++;
	}
	return (current->content);
}

/**
 * @brief Calculates a modified average value based on the content of a linked
 * list.
 *
 * This function traverses a linked list represented by the t_stack structure
 * and calculates a modified average value based on the sum of content values
 * and the count of elements in the linked list. The modification involves
 * adding half of the average again to the result.
 *
 * @param stack A pointer to the head of the linked list (t_stack structure).
 * @return The calculated modified average value.
 */
int	find_media(t_stack *stack)
{
	t_stack	*current;
	long	val;
	long	cont;

	if (stack == NULL)
		return (0);
	current = stack;
	val = 0;
	cont = 0;
	while (current)
	{
		val += current->content;
		current = current->next;
		cont++;
	}
	return ((val / cont) + (val / (cont * 2)));
}

int	find_quart_med(t_stack *stack, long media)
{
	t_stack	*current;
	long	val;
	long	cont;
	long	quart;

	if (stack == NULL)
		return (0);
	current = stack;
	val = 0;
	cont = 0;
	while (current)
	{
		val += current->content;
		cont++;
		current = current->next;
	}
	quart = (val / cont) + (val / (cont * 4));
	if (find_smaller_then(stack, quart, find_smallest(stack)) < quart)
		return (quart);
	return (media);
}