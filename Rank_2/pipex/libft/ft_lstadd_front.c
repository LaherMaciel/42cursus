/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:25:36 by marvin            #+#    #+#             */
/*   Updated: 2022/11/14 19:03:53 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new element to the beginning of a linked list.
 *
 * This function adds the given 'new' element to the beginning of the linked
 * list pointed to by 'lst'. The 'new' element becomes the new head of the
 * linked list, and its 'next' pointer is set to the previous head element.
 *
 * @param lst A pointer to a pointer to the first element of the linked list.
 * @param new The element to be added to the beginning of the linked list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
