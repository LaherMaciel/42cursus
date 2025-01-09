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

#include "push_swap.h"

/**
 * @brief Swap the first two elements at the top of the stack. If there is only
 *    one or no elements, do nothing. And Prints the movement.
 *
 * This function swaps the positions of the first two elements on the stack. If
 * the stack is empty or contains only one element, no operation is performed.
 *
 * @param t_stack** head - A double pointer to the head of the stack.
 * @param char id - Identifier used to distinguish stacks ('a' or 'b') for
 * printing.
 */
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

/**
 * @brief Move the top element from source to the top of destiny stack. Do
 *  nothing if source is empty. And Prints the movement.
 *
 * This function takes the first element from the top of source and places it at
 * the top of destiny. If source is empty, no operation is performed.
 *
 * @param t_stack** src - Pointer to the head of source.
 * @param t_stack** dest - Pointer to the head of destiny.
 * @param char id - Identifier ('a' or 'b') used for printing the correct
 * message.
 */
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

/**
 * @brief Move up all the elements of the stack by 1, making the first element
 * the new last element. And Prints the movement.
 *
 * This function rotates the elements of the stack in a circular fashion. The
 * top element becomes the new last element. If the stack is empty or contains
 * only one element, no rotation is performed.
 *
 * @param t_stack** stack - Pointer to the head of the stack to be rotated.
 * @param char id - Identifier ('a' or 'b') used for printing the correct
 * message.
 */
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
	new_last = ft_lstnew_rem(new_last_value);
	last->next = new_last;
}

/**
 * @brief Move down all the elements of the stack by 1, making the last element
 * the new first element. And Prints the movement.
 *
 * This function rotates the elements of the stack in a circular fashion. The
 * last element becomes the new first element. If the stack is empty or contains
 * only one element, no rotation is performed.
 *
 * @param t_stack** stack - Pointer to the head of the stack to be rotated.
 * @param char id - Identifier ('a' or 'b') used for printing the correct
 * message.
 */
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
