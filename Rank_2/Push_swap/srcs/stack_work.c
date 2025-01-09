/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:26:41 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/06 10:10:04 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Adds a new node with the given content to the top of the stack.
 *
 * @param stack A pointer to the head of the stack (t_stack structure).
 * @param content The content of the new node.
 */
void	push(t_stack **stack, int content)
{
	t_stack	*new_node;

	new_node = (t_stack *) malloc(sizeof(t_stack));
	if (new_node)
	{
		new_node->content = content;
		new_node->next = *stack;
		*stack = new_node;
	}
	else
		ft_printf("Error: Memory allocation failed "\
			"(function copy_stack())\n");
}

/**
 * @brief Removes and returns the content of the top node from the stack.
 *
 * @param head A pointer to the head of the stack (t_stack structure).
 * @return The content of the top node.
 */
int	pop(t_stack **head)
{
	int		content;
	t_stack	*temp;

	temp = *head;
	content = (*head)->content;
	*head = (*head)->next;
	free(temp);
	return (content);
}

/**
 * @brief Prints the content of the stack.
 *
 * @param head A pointer to the head of the stack (t_stack structure).
 */
void	print_stack(t_stack *head)
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf ("%d ", current->content);
		current = current->next;
	}
	ft_printf ("\n");
}

/**
 * @brief Adds a new node with the given content to the end of the stack. Mainly
 * used when copying the original stacks to make the necessary simulations.
 *
 * @param stack A pointer to the head of the stack (t_stack structure).
 * @param content The content of the new node.
 */
void	push_end(t_stack **stack, int content)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node)
	{
		new_node->content = content;
		new_node->next = NULL;
		if (*stack == NULL)
			*stack = new_node;
		else
		{
			temp = *stack;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node;
		}
	}
	else
		ft_printf("Error: Memory allocation failed (function copy_stack())\n");
}

/**
 * @brief Copies the contents of two stacks to new destination stacks.
 *
 * @param source1 A pointer to the head of the first source stack (t_stack
 * structure).
 * @param destination1 A pointer to the head of the first destination stack
 * (t_stack structure).
 * @param source2 A pointer to the head of the second source stack (t_stack
 * structure).
 * @param destination2 A pointer to the head of the second destination stack
 * (t_stack structure).
 */
void	copy_stacks(t_stack *source1, t_stack **destination1,
	t_stack *source2, t_stack **destination2)
{
	if (*destination1 != NULL)
		while (*destination1 != NULL)
			pop(destination1);
	if (*destination2 != NULL)
		while (*destination2 != NULL)
			pop(destination2);
	while (source1)
	{
		push_end(destination1, source1->content);
		source1 = source1->next;
	}
	while (source2)
	{
		push_end(destination2, source2->content);
		source2 = source1->next;
	}
}
