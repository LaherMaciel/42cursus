/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:35:24 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/02 17:56:55 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Moves a block of memory to another location, even if they overlap.
 *
 * This function moves 'n' bytes from the memory location pointed to by 'src' to
 * the memory location pointed to by 'dest'. The copying is done in a way that
 * handles overlapping memory regions correctly.
 *
 * @param dest A pointer to the destination memory block.
 * @param src A pointer to the source memory block.
 * @param n The number of bytes to move.
 * @return A pointer to the destination memory block 'dest'.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ds;
	char	*sc;

	sc = (char *) src;
	ds = dest;
	if (sc < ds)
		while (n--)
			ds[n] = sc[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
