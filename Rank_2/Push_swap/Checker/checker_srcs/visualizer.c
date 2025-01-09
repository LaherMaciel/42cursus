/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:02:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/06 09:56:35 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
#include "checker.h"

void	print_tab_cut2(t_stack *stack_a, t_stack *stack_b, int cont)
{
	while (stack_a)
	{
		if (ft_lstsize_rem(stack_a) >= cont)
			ft_printf("|	%i	|	%i	%d	|			|\n", cont,
				(-cont), (stack_a)->content);
		if (ft_lstsize_rem(stack_a) < cont)
			ft_printf("|	%i	|	%i	%d	|			|\n", cont,
				ft_lstsize_rem(stack_a), (stack_a)->content);
		cont++;
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		if (ft_lstsize_rem(stack_b) >= cont)
			ft_printf("|	%i	|			|	%i	%d	|\n", cont,
				(-cont), (stack_b)->content);
		if (ft_lstsize_rem(stack_b) < cont)
			ft_printf("|	%i	|			|	%i	%d	|\n", cont,
				ft_lstsize_rem(stack_b), (stack_b)->content);
		cont++;
		stack_b = stack_b->next;
	}
}

void	print_tab_cut(t_stack *stack_a, t_stack *stack_b, int cont)
{
	while (stack_a && stack_b)
	{
		if ((ft_lstsize_rem(stack_a)) >= cont
			&& (ft_lstsize_rem(stack_b)) >= cont)
			ft_printf("|	%i	|	%i	%d	|	%i	%d	|\n", cont, (-cont),
				(stack_a)->content, (-cont), (stack_b)->content);
		if ((ft_lstsize_rem(stack_a)) >= cont
			&& (ft_lstsize_rem(stack_b)) < cont)
			ft_printf("|	%i	|	%i	%d	|	%i	%d	|\n", cont, (-cont),
				(stack_a)->content, ft_lstsize_rem(stack_b), (stack_b)->content);
		if ((ft_lstsize_rem(stack_a)) < cont && (ft_lstsize_rem(stack_b)) < cont)
			ft_printf("|	%i	|	%i	%d	|	%i	%d	|\n", cont,
				ft_lstsize_rem(stack_a), (stack_a)->content,
					ft_lstsize_rem(stack_b),
				(stack_b)->content);
		if ((ft_lstsize_rem(stack_a)) < cont
			&& (ft_lstsize_rem(stack_b)) >= cont)
			ft_printf("|	%i	|	%i	%d	|	%i	%d	|\n", cont,
				ft_lstsize_rem(stack_a), (stack_a)->content, (-cont),
				(stack_b)->content);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
		cont++;
	}
	print_tab_cut2(stack_a, stack_b, cont);
}

void	print_tab(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n---------------------------------"\
	"--------------------------------\n");
	ft_printf("|	PS	|	NMA	A	|	NMB	B	|\n");
	ft_printf("|---------------|-------------"\
	"----------|-----------------------|\n");
	print_tab_cut(stack_a, stack_b, 0);
	ft_printf("----------------------------------------"\
		"-------------------------\n");
}
 */