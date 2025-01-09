/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:39:30 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:11:15 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates two strings with size-bound protection and returns the
 * resulting length.
 *
 * This function concatenates the string 'src' to the end of the string 'dest'
 * with a size limit of 'n'. It ensures that the total length of the
 * concatenated string does not exceed 'n'. If 'n' is less than or equal to the
 * length of 'dest', no concatenation occurs. The concatenated string is
 * null-terminated, and the function returns the total length that the
 * concatenated string would have been if there were no size restrictions.
 *
 * @param dest The destination string to which 'src' will be concatenated.
 * @param src The source string to be concatenated to 'dest'.
 * @param n The size limit for the concatenated string.
 * @return The length of the concatenated string that would have been created
 * without size restrictions.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;

	i = 0;
	dest_size = ft_strlen(dest);
	if (size <= dest_size || size == 0)
		return (size + ft_strlen(src));
	while (src[i] && i < size - dest_size - 1)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + ft_strlen(src));
}
