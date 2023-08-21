/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:14:42 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/02 19:27:56 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills a block of memory with a specified value.
 *
 * This function sets each byte in the memory block pointed to by 'str' to the
 * value of 'c'. The operation is repeated 'n' times.
 *
 * @param str A pointer to the memory block to be filled.
 * @param c The value to be set in each byte.
 * @param n The number of bytes to fill.
 * @return A pointer to the memory block 'str'.
 */
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((unsigned char *)str)[i] = c;
	return (str);
}
