/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:08:52 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/06 11:05:55 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap the top two elements of both stack_a and stack_b.
 *
 * This function performs two swap operations, one on stack_a and one on
 * stack_b. It swaps the first two elements at the top of each stack. If either
 * stack is empty or has only one element, the corresponding swap operation is
 * skipped.
 *
 * @param t_stack** stack_a - Pointer to the head of stack_a.
 * @param t_stack** stack_b - Pointer to the head of stack_b.
 */
void	ft_swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		ft_swap(stack_b, 'b');
	else if (*stack_b == NULL || (*stack_b)->next == NULL)
		ft_swap(stack_a, 'a');
	else
	{
		ft_printf("ss\n");
		ft_swap(stack_a, 'A');
		ft_swap(stack_b, 'B');
	}
}

/**
 * @brief Rotate the elements of both stack_a and stack_b.
 *
 * This function performs two rotate operations, one on stack_a and one on
 * stack_b. It moves the Fist element to the end in each stack, effectively
 * rotating the elements in a circular fashion, up by 1. If either stack is
 * empty or contains only one element, the corresponding rotate operation is
 * skipped.
 *
 * @param t_stack** stack_a - Pointer to the head of stack_a.
 * @param t_stack** stack_b - Pointer to the head of stack_b.
 */
void	ft_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		ft_rotate(stack_b, 'b');
	else if (*stack_b == NULL || (*stack_b)->next == NULL)
		ft_rotate(stack_a, 'a');
	else
	{
		ft_printf("rr\n");
		ft_rotate(stack_a, 'A');
		ft_rotate(stack_b, 'B');
	}
}

/**
 * @brief Perform a double reverse rotate on both stack_a and stack_b.
 *
 * This function combines two reverse rotate operations, one on stack_a and one
 * on stack_b. It moves the last element to the top in each stack, effectively
 * rotating the elements in a circular fashion in the opposite direction, down
 * by 1. If either stack is empty or contains only one element, the
 * corresponding reverse rotate operation is skipped.
 *
 * @param t_stack** stack_a - Pointer to the head of stack_a.
 * @param t_stack** stack_b - Pointer to the head of stack_b.
 */
void	ft_reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		ft_reverse_rotate(stack_b, 'b');
	else if (*stack_b == NULL || (*stack_b)->next == NULL)
		ft_reverse_rotate(stack_a, 'a');
	else
	{
		ft_printf("rrr\n");
		ft_reverse_rotate(stack_a, 'A');
		ft_reverse_rotate(stack_b, 'B');
	}
}
