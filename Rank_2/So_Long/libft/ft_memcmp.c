/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:19:18 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/02 19:15:23 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two memory blocks up to a specified length.
 *
 * This function compares the first 'n' bytes of two memory blocks 'str1' and
 * 'str2'. The comparison is performed byte by byte, and the result indicates
 * the relationship between the contents of the two blocks.
 *
 * @param str1 A pointer to the first memory block.
 * @param str2 A pointer to the second memory block.
 * @param n The number of bytes to compare.
 * @return -1 if 'str1' is less than, 0 if equal to, or 1 if is greater
 *         than 'str2'.
 */
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			a;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *) str1;
	c2 = (unsigned char *) str2;
	a = -1;
	while (++a < n)
	{
		if (c1[a] != c2[a])
		{
			if ((c1[a] - c2[a]) < 0)
				return (-1);
			else
				return (1);
		}
	}
	return (0);
}
