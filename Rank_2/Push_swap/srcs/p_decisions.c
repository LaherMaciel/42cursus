/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_decisions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:05:21 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/18 12:07:38 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Determines the decision to be made in the stack.
 *
 * This function decides the action to be taken (push or rotate) based on the
 * current state of the source and destination stacks, as well as the specified
 * positions. The decision is represented as a string indicating the action to
 * be performed.
 *
 * @param src A pointer to the head of the source stack (t_stack structure).
 * @param dst A pointer to the head of the destination stack (t_stack
 * structure).
 * @param pos_src The position (index) in the source stack.
 * @param pos_dst The position (index) in the destination stack.
 * @return A string representing the decision to be made. Returns NULL if no
 * action is required.
 */
char	*p_decisions(t_stack *src, t_stack *dst, int pos_src, int pos_dst)
{
	int	final_pos_2;

	if (dst != NULL && ft_lstsize_rem(dst) <= 2)
		final_pos_2 = 1 - ft_lstsize_rem(dst);
	else if (find_val(dst, pos_dst) < find_val(src, pos_src))
		final_pos_2 = 1;
	else
		final_pos_2 = 0;
	if (pos_src == 0 && pos_dst == final_pos_2)
		return ((char *) "pa");
	else if (pos_src < 0 && pos_dst < final_pos_2)
		return ((char *) "rr");
	else if (pos_src > 0 && pos_dst > final_pos_2)
		return ((char *) "rrr");
	else if (pos_src < 0)
		return ((char *) "rb");
	else if (pos_src > 0)
		return ((char *) "rrb");
	else if (pos_dst < final_pos_2)
		return ((char *) "ra");
	else if (pos_dst > final_pos_2)
		return ((char *) "rra");
	return (NULL);
}

/**
 * @brief Adjusts positions based on final positions for continuous
 * decision-making.
 *
 * This function adjusts two positions (*pos_1 and *pos_2) based on the final
 * position (final_pos_2) to facilitate continuous decision-making in certain
 * scenarios.
 *
 * @param pos_1 A pointer to the first position (index).
 * @param pos_2 A pointer to the second position (index).
 * @param final_pos_2 The final position used as a reference.
 */
void	p_decisison_cont_aux(int *pos_1, int *pos_2, int final_pos_2)
{
	if (*pos_1 < 0 && *pos_2 < final_pos_2)
	{
		(*pos_1)++;
		(*pos_2)++;
	}
	else if (*pos_1 > 0 && *pos_2 > final_pos_2)
	{
		(*pos_1)--;
		(*pos_2)--;
	}
	else if (*pos_1 < 0)
		(*pos_1)++;
	else if (*pos_1 > 0)
		(*pos_1)--;
	else if (*pos_2 < final_pos_2)
		(*pos_2)++;
	else if (*pos_2 > final_pos_2)
		(*pos_2)--;
}

/**
 * @brief Determines the number of continuous decisions needed for a push
 * operation in a stack.
 *
 * This function calculates the number of continuous decisions needed to reach a
 * specific state during a push operation in a stack. The decision-making
 * process is based on the current state of the source and destination stacks,
 * as well as the specified positions.
 *
 * @param src A pointer to the head of the source stack (t_stack structure).
 * @param dst A pointer to the head of the destination stack (t_stack
 * structure).
 * @param pos_src The initial position (index) in the source stack.
 * @param pos_dst The initial position (index) in the destination stack.
 * @return The number of continuous decisions needed to reach the desired state.
 */
int	p_decisions_cont(t_stack *src, t_stack *dst, int pos_src, int pos_dst)
{
	int	mov;
	int	cont;
	int	final_pos_2;

	cont = 0 ;
	mov = 0;
	if (ft_lstsize_rem(dst) <= 2)
		final_pos_2 = 1 - ft_lstsize_rem(dst);
	else if (find_val(src, pos_src) < find_val(dst, pos_dst))
		final_pos_2 = 0;
	else
		final_pos_2 = 1;
	while (mov == 0)
	{
		if (pos_src == 0 && pos_dst == final_pos_2)
			mov = 1;
		p_decisison_cont_aux(&pos_src, &pos_dst, final_pos_2);
		cont++;
	}
	return (cont);
}
