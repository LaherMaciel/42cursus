/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:48:30 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/02 21:18:47 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of a byte in a memory block.
 *
 * This function scans the initial 'n' bytes of the memory block pointed to by
 * 'str' for the byte 'c'. If the byte is found, a pointer to its location is
 * returned. If the byte is not found, the function returns NULL.
 *
 * Both c and the bytes of the memory area pointed to by s are interpreted as
 * unsigned char.
 *
 * @param str A pointer to the memory block to be searched.
 * @param c The byte to be located.
 * @param n The number of bytes to search in the memory block.
 * @return A pointer to the first occurrence of 'c' in the memory block, or NULL
 * if not found.
 */
void	*ft_memchr(void *str, int c, size_t n)
{
	size_t			a;
	unsigned char	*s;

	s = (unsigned char *)str;
	a = 0;
	while (a < n)
	{
		if (s[a] == (unsigned char) c)
			return ((void *)s + a);
		a++;
	}
	return (0);
}
