/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:46:04 by marvin            #+#    #+#             */
/*   Updated: 2022/11/14 18:29:20 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Creates a new node for a linked list with the given content.
 *
 * This function allocates memory for a new node in a linked list represented by
 * the t_stack structure. It initializes the node with the provided content and
 * sets its next pointer to NULL.
 *
 * @param content The content value to be stored in the new node.
 * @return A pointer to the newly created node. Returns NULL if memory
 * allocation fails.
 */
t_stack	*ft_lstnew_rem(int content)
{
	t_stack	*new_list;

	new_list = (t_stack *) malloc(sizeof(t_stack));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
