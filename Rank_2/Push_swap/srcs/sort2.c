/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:46:56 by lwencesl          #+#    #+#             */
/*   Updated: 2024/06/26 17:46:07 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast_rem(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	check_order_ok_rev(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->content < stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/**
 * @brief Sorts three elements in a stack.
 *
 * This function sorts three elements in a stack represented by the t_stack
 * structure. It performs a series of operations to achieve the sorting.
 *
 * @param stack A pointer to the head of the stack (t_stack structure).
 * @param id The identifier specifying the stack (used in operations).
 */
void	sort_s_3(t_stack **stack, char id)
{
	int	out;

	out = 0;
	if (!stack)
		return ;
	while (out != 1)
	{
		if ((*stack)->content > (*stack)->next->content
			&& (*stack)->next->content > (*stack)->next->next->content)
			ft_rotate(stack, id);
		else if (((*stack)->content < (*stack)->next->content)
			&& ((*stack)->content > (*stack)->next->next->content))
			ft_reverse_rotate(stack, id);
		else if (((*stack)->content > (*stack)->next->content)
			&& ((*stack)->content > (*stack)->next->next->content))
			ft_rotate(stack, id);
		else if (((*stack)->content < (*stack)->next->content)
			&& ((*stack)->next->content > (*stack)->next->next->content))
			ft_reverse_rotate(stack, id);
		else if (((*stack)->content > (*stack)->next->content))
			ft_swap(stack, id);
		else
			out = 1;
	}
}

int	sort_s_3_rev_aux(t_stack **stack, char id)
{
	if ((*stack)->content < (*stack)->next->content
		&& (*stack)->next->content < (*stack)->next->next->content
		&& ft_lstsize_rem(*stack) == 3)
		ft_rotate(stack, id);
	else if (((*stack)->content > (*stack)->next->content)
		&& ((*stack)->content < (*stack)->next->next->content)
		&& ft_lstsize_rem(*stack) == 3)
		ft_reverse_rotate(stack, id);
	else if (((*stack)->content < (*stack)->next->content)
		&& ((*stack)->content < (*stack)->next->next->content)
		&& ft_lstsize_rem(*stack) == 3)
		ft_rotate(stack, id);
	else
		return (1);
	return (0);
}

void	sort_s_3_rev(t_stack **stack, char id)
{
	int	out;

	out = 0;
	if (!stack)
		return ;
	while (out != 1)
	{
		if (sort_s_3_rev_aux(stack, id) == 1)
		{
			if (((*stack)->content > (*stack)->next->content)
				&& ((*stack)->next->content < (*stack)->next->next->content)
				&& ft_lstsize_rem(*stack) == 3)
				ft_reverse_rotate(stack, id);
			else if (((*stack)->content < (*stack)->next->content))
				ft_swap(stack, id);
			else
				out = 1;
		}
	}
}
