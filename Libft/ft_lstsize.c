/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:38:53 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/22 15:38:21 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the number of elements in a linked list.
 *
 * This function counts the number of elements in the linked list pointed to by
 * 'lst'. It iterates through the list and increments a counter for each element
 * encountered.
 *
 * @param lst The first element of the linked list.
 * @return The number of elements in the linked list.
 */
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
