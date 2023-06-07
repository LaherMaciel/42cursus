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

// find and return the smallest value of the stack
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

// find and return the value bigger, closest to 'val'
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

// find and return the biggest value of the stack
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

// return the position of the 'val'
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
