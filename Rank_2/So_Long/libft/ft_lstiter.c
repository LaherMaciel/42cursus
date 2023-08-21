/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:39:58 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/15 19:00:59 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates over each element of a linked list and applies a function to
 * each element's content.
 *
 * This function iterates through the linked list pointed to by 'lst' and
 * applies the provided function 'f' to the content of each element. The purpose
 * of this function is to perform a specific operation on each element's content
 * without modifying the structure of the list.
 *
 * @param lst The first element of the linked list.
 * @param f A function pointer that takes a pointer to an element's content and
 * performs an operation on it.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
