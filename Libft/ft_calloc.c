/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:05:36 by lwencesl          #+#    #+#             */
/*   Updated: 2022/10/29 22:45:07 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and initializes memory for an array of elements.

* This function allocates memory for an array containing 'n' elements, each of
  size 'size' bytes. The allocated memory is then initialized to zero using the
  ft_bzero function.

* @param n The number of elements in the array.
* @param size The size of each element in bytes.
* @return A pointer to the allocated and initialized memory, or NULL if
allocation fails.
 */
void	*ft_calloc(size_t n, size_t size)
{
	void	*i;

	i = malloc(n * size);
	if (!i)
		return (NULL);
	ft_bzero(i, n * size);
	return (i);
}
