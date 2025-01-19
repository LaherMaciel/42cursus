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
 *
 * @return function returns an integer less than, equal to, or greater than zero
 * if the first n bytes of s1 is found, respectively, to be less than, to match,
 * or be greater than the first n bytes of s2.
 *
 * For a nonzero return value, the sign is determined by the sign of the
 * difference between the first pair of bytes (interpreted as unsigned char)
 * that differ in s1 and s2.
 *
 * If n is zero, the return value is zero.
 */
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			a;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) str1;
	s2 = (unsigned char *) str2;
	a = -1;
	while (++a < n)
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
	return (0);
}
