/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:46:04 by marvin            #+#    #+#             */
/*   Updated: 2023/06/22 15:26:07 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new element for a linked list.
 *
 * This function creates a new element for a linked list with the provided
 * 'content'. The 'content' pointer is assigned to the element's content, and
 * the 'next' pointer is set to NULL.
 *
 * @param content The content to be assigned to the new element.
 * @return A pointer to the newly created element, or NULL if memory allocation
 * fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *) malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
