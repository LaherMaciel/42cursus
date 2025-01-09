/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_condicions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:41:30 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 18:41:30 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the number of movements required to reach a position on the
 * stack.
 *
 * @param pos The target position on the stack.
 * @param stack_size The size of the stack.
 * @return The number of movements needed to reach the target position.
 */
int	nr_movs(int pos, int stack_size)
{
	int	needed_movs;

	if (pos == 0)
		return (pos);
	if (pos < 0)
		pos = stack_size + pos;
	else if (pos >= stack_size)
		pos = pos - stack_size;
	if (pos > (stack_size / 2))
		needed_movs = stack_size - pos;
	else
		needed_movs = (pos) * (-1);
	return (needed_movs);
}

/**
 * @brief Finds the best position on the stack for a push operation.
 *
 * This function iteratively finds positions on the source stack for a push
 * operation, updating the positions based on certain conditions.
 *
 * @param src A pointer to the head of the source stack (t_stack structure).
 * @param pos_1 A pointer to the first position.
 * @param cont A pointer to the counter for iteration.
 */
void	find_pos_1(t_stack *src, int *pos_1, int *cont)
{
	int	half;

	half = ft_lstsize_rem(src) / 2;
	if (half == 0)
		half = 1;
	if (*cont <= half)
		*pos_1 = *cont * (-1);
	else
		*pos_1 = ft_lstsize_rem(src) - *cont;
	*cont = *cont + 1;
}

/**
 * @brief Finds the best move for a push operation.
 *
 * This function calculates the best move for a push operation based on the
 * positions on the source and destination stacks.
 *
 * @param src A pointer to the head of the source stack (t_stack structure).
 * @param dst A pointer to the head of the destination stack (t_stack
 * structure).
 * @param pos_1 The first position on the source stack.
 * @param pos_2 A pointer to the second position on the destination stack.
 * @return The number of movements needed for the best move.
 */
int	best_move_pa_aux_2(t_stack *src, t_stack *dst,
	int *pos_1, int *pos_2)
{
	int	movs1;
	int	movs2;

	if (find_val(src, *pos_1) < find_smallest(dst))
		*pos_2 = nr_movs(find_pos(dst, find_smallest(dst)),
				ft_lstsize_rem(dst));
	else
		*pos_2 = nr_movs(find_pos(dst, find_smaller_then(dst,
						find_val(src, *pos_1), find_smallest(dst))),
				ft_lstsize_rem(dst));
	movs1 = p_decisions_cont(src, dst, *pos_1, *pos_2);
	if (find_val(src, *pos_1) > find_biggest(dst))
		*pos_2 = nr_movs(find_pos(dst, find_biggest(dst)),
				ft_lstsize_rem(dst));
	else
		*pos_2 = nr_movs(find_pos(dst, find_bigger_then(dst,
						find_val(src, *pos_1), find_biggest(dst))),
				ft_lstsize_rem(dst));
	movs2 = p_decisions_cont(src, dst, *pos_1, *pos_2);
	if (movs1 <= movs2)
		return (movs1);
	return (movs2);
}

/**
 * @brief Finds the best move for a push operation.
 *
 * This function determines the best move for a push operation, considering
 * different scenarios.
 *
 * @param src A pointer to the head of the source stack (t_stack structure).
 * @param dst A pointer to the head of the destination stack (t_stack
 * structure).
 * @param pos_1 The first position on the source stack.
 * @param pos_2 A pointer to the second position on the destination stack.
 * @return The number of movements needed for the best move.
 */
int	best_stack_pa_mov_aux(t_stack *src, t_stack *dst, int *pos_1, int *pos_2)
{
	int	movs;

	if (dst == NULL)
	{
		movs = *pos_1;
		if (movs < 0)
			movs = movs * (-1);
	}
	else
		movs = best_move_pa_aux_2(src, dst, pos_1, pos_2);
	return (movs);
}

/**
 * @brief Finds the best move for a push operation.
 *
 * This function iterates through positions on the source stack to find the best
 * move for a push operation to the destination stack.
 *
 * @param src A pointer to the head of the source stack (t_stack structure).
 * @param dst A pointer to the head of the destination stack (t_stack
 * structure).
 * @param best_movs A pointer to an array storing information about the best
 * move.
 * @return A pointer to the array containing information about the best move.
 */
int	*best_stack_pa_mov(t_stack *src,
		t_stack *dst, int *best_movs)
{
	int	movs;
	int	pos_1;
	int	pos_2;
	int	cont;

	cont = 0;
	pos_1 = -1;
	pos_2 = 0;
	while (cont < ft_lstsize_rem(src))
	{
		find_pos_1(src, &pos_1, &cont);
		movs = best_stack_pa_mov_aux(src, dst, &pos_1, &pos_2);
		if (movs < best_movs[0])
		{
			best_movs[0] = movs;
			best_movs[1] = pos_1;
			best_movs[2] = pos_2;
		}
	}
	return (best_movs);
}
