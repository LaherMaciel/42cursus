/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:40:30 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/15 17:44:23 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes a single element from a linked list.
 *
 * This function deletes the given list element 'lst' by freeing the memory
 * allocated for its content using the provided 'del' function and then
 * deallocating the memory for the element itself.
 *
 * @param lst The element to be deleted.
 * @param del A function pointer that takes a pointer to an element's content
 * and frees its memory.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
