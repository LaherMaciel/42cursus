/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:23:40 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:11:36 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Safely copies a string into a destination buffer with size-bound
 * protection.
 *
 * This function copies the string 'src' into the destination buffer 'dest' with
 * a size limit of 'size'. It ensures that the destination buffer is
 * null-terminated and prevents buffer overflow by copying at most 'size - 1'
 * characters from 'src'. The destination buffer is null-terminated even if the
 * string has been truncated due to the size limit. The function returns the
 * length of the source string, regardless of whether truncation occurred.
 *
 * @param dest The destination buffer where 'src' will be copied.
 * @param src The source string to be copied to 'dest'.
 * @param size The size of the destination buffer.
 * @return The length of the source string (not the length of the copied
 * portion).
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size -1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
