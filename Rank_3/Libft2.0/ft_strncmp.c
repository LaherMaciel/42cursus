/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:44:33 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:12:42 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two strings up to a specified number of characters.
 *
 * This function compares the strings 'str1' and 'str2' up to 'n' characters or
 * until a null-terminator is encountered in either string. It returns an
 * integer value indicating the comparison result:
 * - Returns a value less than 0 if 'str1' is lexicographically less than
 *   'str2'.
 * - Returns 0 if both strings are lexicographically equal up to 'n' characters.
 * - Returns a value greater than 0 if 'str1' is lexicographically greater than
 *   'str2'.
 *
 * @param str1 The first string to be compared.
 * @param str2 The second string to be compared.
 * @param n The maximum number of characters to compare.
 * @return An integer indicating the comparison result.
 */
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		n = ft_strlen(str1);
	while (a < n && (str1[a] || str2[a]))
	{
		if (str1[a] != str2[a])
			return ((unsigned char)str1[a] - (unsigned char)str2[a]);
		a++;
	}
	return (0);
}
