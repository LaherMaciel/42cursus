/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:32:08 by lwencesl          #+#    #+#             */
/*   Updated: 2024/06/26 18:41:59 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the first number above the median by traversing both from the top
 * to the middle and from the bottom to the middle of the stack.
 * 
 * The function calculates the median, then iterates through the stack from both
 * ends towards the center, comparing values against the calculated median.
 * 
 * @param stack A pointer to the stack
 * @param cont1 Counter for the top-half traversal
 * @param cont2 Counter for the bottom-half traversal
 * @return The index of the first number above the median
 */
int	find_above_media_reverse(t_stack *stack, int cont1, int cont2)
{
	t_stack	*current;
	int		media;

	media = find_media(stack);
	current = stack;
	while (cont1 > (-ft_lstsize_rem(stack) / 2))
	{
		if (find_val(stack, cont1) >= media)
			break ;
		current = current->next;
		cont1--;
	}
	while (cont2 < (ft_lstsize_rem(stack) / 2))
	{
		if (find_val(stack, cont2) >= media)
			break ;
		current = current->next;
		cont2++;
	}
	if ((cont1 * (-1)) <= cont2)
		return (cont1);
	else if ((cont1 * (-1)) > cont2)
		return (cont2);
	return (0);
}

int	find_above_quart_media_reverse(t_stack *stack, int cont1, int cont2)
{
	t_stack	*current;
	int		media;

	media = find_quart_med(stack, find_media(stack));
	current = stack;
	while (cont1 > (-ft_lstsize_rem(stack) / 2))
	{
		if (find_val(stack, cont1) >= media)
			break ;
		current = current->next;
		cont1--;
	}
	while (cont2 < (ft_lstsize_rem(stack) / 2))
	{
		if (find_val(stack, cont2) >= media)
			break ;
		current = current->next;
		cont2++;
	}
	if ((cont1 * (-1)) <= cont2)
		return (cont1);
	else if ((cont1 * (-1)) > cont2)
		return (cont2);
	return (0);
}

/**
 * @brief Finds the first number below the median by traversing both from the top
 * to the middle and from the bottom to the middle of the stack.
 * 
 * The function calculates the median, then iterates through the stack from both
 * ends towards the center, comparing values against the calculated median.
 * 
 * @param stack A pointer to the stack
 * @param cont1 Counterfind_above_media for the top-half traversal
 * @param cont2 Counter for the bottom-half traversal
 * @return The index of the first number below the median
 */
int	find_above_media(t_stack *stack, int cont1, int cont2)
{
	t_stack	*current;
	int		media;

	media = find_media(stack);
	current = stack;
	while (cont1 > (-ft_lstsize_rem(stack) / 2))
	{
		if (find_val(stack, cont1) <= media)
			break ;
		current = current->next;
		cont1--;
	}
	while (cont2 < (ft_lstsize_rem(stack) / 2))
	{
		if (find_val(stack, cont2) <= media)
			break ;
		current = current->next;
		cont2++;
	}
	if ((cont1 * (-1)) <= cont2)
		return (cont1);
	else if ((cont1 * (-1)) > cont2)
		return (cont2);
	return (0);
}

int	find_above_quart_media(t_stack *stack, int cont1, int cont2)
{
	t_stack	*current;
	int		quart;

	quart = find_quart_med(stack, find_media(stack));
	current = stack;
	while (cont1 > (-ft_lstsize_rem(stack) / 2))
	{
		if (find_val(stack, cont1) <= quart)
			break ;
		current = current->next;
		cont1--;
	}
	while (cont2 < (ft_lstsize_rem(stack) / 2))
	{
		if (find_val(stack, cont2) <= quart)
			break ;
		current = current->next;
		cont2++;
	}
	if ((cont1 * (-1)) <= cont2)
		return (cont1);
	else if ((cont1 * (-1)) > cont2)
		return (cont2);
	return (0);
}
