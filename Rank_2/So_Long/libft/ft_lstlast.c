/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:32:53 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/22 15:26:51 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the last element of a linked list.
 *
 * This function traverses the linked list pointed to by 'lst' and returns a
 * pointer to the last element. If the input list is empty (NULL), the function
 * returns NULL.
 *
 * @param lst The first element of the linked list.
 * @return A pointer to the last element of the linked list, or NULL if the list
 * is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
