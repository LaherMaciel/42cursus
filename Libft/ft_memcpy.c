/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:50:42 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/02 19:26:19 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a block of memory from one location to another.
 *
 * This function copies 'n' bytes from the memory location pointed to by 'src'
 * to the memory location pointed to by 'dest'. The copying is done byte by
 * byte.
 *
 * @param dest A pointer to the destination memory block.
 * @param src A pointer to the source memory block.
 * @param n The number of bytes to copy.
 * @return A pointer to the destination memory block 'dest'.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	i = -1;
	if (!dest && !src)
		return (0);
	while (++i < n)
		d[i] = s[i];
	return (dest);
}
