/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:38:53 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/18 00:38:13 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the size (number of elements) of a linked list.
 *
 * This function traverses a linked list represented by the t_stack structure
 * and counts the number of elements in the list.
 *
 * @param lst A pointer to the head of the linked list (t_stack structure).
 * @return The number of elements in the linked list.
 */
int	ft_lstsize_rem(t_stack *lst)
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
