/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laher_maciel <laher_maciel@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:39:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/12 19:50:27 by laher_maciel     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//send an error message if the program recieves a number more then 1 time
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

// check if theres any duplicaded value.
int	contains_duplicate_values(t_stack *head)
{
	t_stack	*current1;
	t_stack	*current2;

	current1 = head;
	current2 = NULL;
	if (head == NULL)
		return (1);
	while (current1 != NULL)
	{
		current2 = current1->next;
		while (current2 != NULL)
		{
			if (current1->content == current2->content)
				return (0);
			current2 = current2->next;
		}
		current1 = current1->next;
	}
	return (1);
}

int	check_order_ok(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	input_ok(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
		}
	}
	return (1);
}
