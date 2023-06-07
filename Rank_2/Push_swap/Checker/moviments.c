/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:09:38 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 03:09:38 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Swap the first 2 elements at the top of stack. 
// Do nothing if there is only one or no elements.
void	ft_swap(t_stack **head, char id)
{
	t_stack	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	if (id == 'a' || id == 'b')
		ft_printf("s%c\n", id);
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

// Take the first element at the top of the stack_2 and put it at the
// top of the stack_1. Do nothing if stack_2 is empty.
// pa = stack b -> stack a ||  pb = stack a -> stack b
void	ft_pass_to(t_stack **src, t_stack **dest, char id)
{
	t_stack	*new_node;
	int		content;

	if (!*src || !(*src))
		return ;
	if (id == 'a' || id == 'b')
		ft_printf("p%c\n", id);
	content = pop(src);
	new_node = (t_stack *) malloc(sizeof(t_stack));
	new_node->content = content;
	if (dest)
		new_node->next = *dest;
	*dest = new_node;
}

// Shift up all elements of the stack by 1. 
// The first element becomes the last one.
void	ft_rotate(t_stack **stack, char id)
{
	int		new_last_value;
	t_stack	*new_last;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	if (id == 'a' || id == 'b')
		ft_printf("r%c\n", id);
	new_last_value = pop(stack);
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	new_last = ft_lstnew(new_last_value);
	last->next = new_last;
}

// Shift down all elements of the stack by 1. 
// The last element becomes the first one.
void	ft_reverse_rotate(t_stack **stack, char id)
{
	t_stack	*new_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (id == 'a' || id == 'b')
		ft_printf("rr%c\n", id);
	new_last = *stack;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	last = new_last->next;
	last->next = *stack;
	*stack = last;
	new_last->next = NULL;
}
