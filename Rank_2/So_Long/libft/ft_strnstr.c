/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:44:42 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:17:44 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the first occurrence of a substring within a given length of a
 * main string.
 *
 * This function searches for the first occurrence of the substring 'little'
 * within the first 'len' characters of the main string 'big'. If 'little' is an
 * empty string, a pointer to 'big' is returned. If 'len' is less than or equal
 * to 0, or if 'little' is not found within the specified length, NULL is
 * returned. Otherwise, a pointer to the first occurrence of 'little' within
 * 'big' is returned.
 *
 * @param big The main string to search within.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search within in 'big'.
 * @return A pointer to the first occurrence of 'little' within 'big', or NULL
 * if not found or invalid parameters.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	if (little[0] == '\0')
		return ((char *)big);
	if (len <= 0)
		return (NULL);
	a = 0;
	while (big[a])
	{
		b = 0;
		while (((char *)big)[a + b] == ((char *)little)[b] \
		&& (a + b) < len)
		{
			if (little[b] == '\0')
				return ((char *)big + a);
			b++;
		}
		if (little[b] == '\0')
			return ((char *)big + a);
		a++;
	}
	return (NULL);
}
