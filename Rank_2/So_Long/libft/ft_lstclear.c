/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:09:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/06 17:46:24 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Clears a linked list and frees its memory.
 *
 * This function clears the linked list pointed to by 'lst' by deallocating
 * memory for each element and its associated content using the provided 'del'
 * function. The 'del' function should be capable of freeing the memory of a
 * single list element. After clearing the list, the 'lst' pointer is set to
 * NULL.
 *
 * @param lst A pointer to a pointer to the first element of the linked list.
 * @param del A function pointer that takes a pointer to an element's content
 * and frees its memory.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
