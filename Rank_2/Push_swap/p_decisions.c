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

char	*p_decisions(t_stack *src, t_stack *dst, int pos_src, int pos_dst)
{
	int	final_pos_2;

	if (dst != NULL && ft_lstsize(dst) <= 2)
			final_pos_2 = 1 - ft_lstsize(dst);
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

int	p_decisions_cont(t_stack *src, t_stack *dst, int pos_src, int pos_dst)
{
	int	mov;
	int	cont;
	int	final_pos_2;

	cont = 0 ;
	mov = 0;
	if (ft_lstsize(dst) <= 2)
			final_pos_2 = 1 - ft_lstsize(dst);
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
