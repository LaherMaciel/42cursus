/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:08:38 by lawences          #+#    #+#             */
/*   Updated: 2024/06/26 19:04:10 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_s_by4(t_stack **stack, char id)
{
	int		out;
	t_stack	*last;

	out = 0;
	if (!stack)
		return ;
	while (out != 1)
	{
		last = ft_lstlast_rem(*stack);
		if (((*stack)->content > (*stack)->next->content)
			&& (*stack)->content < last->content)
			ft_swap(stack, id);
		else if ((*stack)->content > last->content)
			ft_rotate(stack, id);
		else if (((*stack)->content < last->content)
			&& (*stack)->content != find_biggest(*stack)
			&& last->content != find_smallest(*stack))
			ft_reverse_rotate(stack, id);
		else if (((*stack)->content > (*stack)->next->content))
			ft_swap(stack, id);
		else
			out = 1;
	}
}

int	sort_s_by4_rev_aux(t_stack **stack, char id, t_stack *last)
{
	if (((*stack)->content < (*stack)->next->content)
		&& (*stack)->content > last->content)
		ft_swap(stack, id);
	else if (((*stack)->content > last->content)
		&& (*stack)->content != find_biggest(*stack)
		&& last->content != find_smallest(*stack))
		ft_reverse_rotate(stack, id);
	else if (((*stack)->content > last->content)
		&& (*stack)->content != find_biggest(*stack)
		&& last->content != find_smallest(*stack))
		ft_reverse_rotate(stack, id);
	else 
		return (1);
	return (0);
}

void	sort_s_by4_rev(t_stack **stack, char id)
{
	int		out;
	t_stack	*last;

	out = 0;
	if (!stack)
		return ;
	while (out != 1)
	{
		last = ft_lstlast_rem(*stack);
		if (((*stack)->content < (*stack)->next->content)
			&& (*stack)->content > last->content
			&& (*stack)->content < (*stack)->next->next->content)
			out = 1;
		if (sort_s_by4_rev_aux(stack, id, last) == 1)
		{
			if ((*stack)->content == find_smallest(*stack)
				&& (*stack)->next->content == find_biggest(*stack))
				ft_rotate(stack, id);
			else
				out = 1;
		}
	}
}

void	sort_cut2(t_stack **stack_a, t_stack **stack_b)
{
	ft_pass_to(stack_a, stack_b, 'b');
	if (check_order_ok(*stack_a) == 0)
		return ;
	if (ft_lstsize_rem(*stack_a) + ft_lstsize_rem(*stack_b) < 50)
	{
		if (ft_lstsize_rem(*stack_b) != 0)
		{
			if (ft_lstsize_rem(*stack_b) % 3 == 0)
				sort_s_3_rev(stack_b, 'b');
			else if ((ft_lstsize_rem(*stack_b) % 4 == 0)
				&& ((*stack_b)->next)
				&& (*stack_b)->content < (*stack_b)->next->content)
				sort_s_by4_rev(stack_b, 'b');
		}
		else if ((ft_lstsize_rem(*stack_b) == 2) && ((*stack_b)->next)
			&& (*stack_b)->content < (*stack_b)->next->content)
			ft_swap(stack_b, 'b');
	}
	if ((*stack_b)->content % 2 != 0)
		ft_rotate(stack_b, 'b');
}

void	sort_cut3(t_stack **stack_a, t_stack **stack_b)
{
	ft_pass_to(stack_a, stack_b, 'b');
	if ((*stack_b)->content % 2 != 0)
		ft_rotate(stack_b, 'b');
}
