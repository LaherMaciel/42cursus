/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:35:04 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/18 00:48:31 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new linked list by applying a function to each element of an
 * existing list.
 *
 * This function creates a new linked list by applying the function 'f' to each
 * element's content in the input list 'lst'. The resulting content from 'f' is
 * used to create new elements in the new linked list. If memory allocation
 * fails during this process, the function ensures proper cleanup by deleting
 * the new list and any elements created so far using the 'del' function.
 *
 * @param lst The first element of the input linked list.
 * @param f A function pointer that takes a pointer to an element's content and
 * returns a new content pointer.
 * @param del A function pointer that takes a pointer to an element's content
 * and frees its memory.
 * @return A pointer to the first element of the new linked list, or NULL if
 * memory allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	void	*contente;

	new = NULL;
	while (lst)
	{
		contente = f(lst->content);
		temp = ft_lstnew(contente);
		if (!temp)
		{
			del(contente);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
