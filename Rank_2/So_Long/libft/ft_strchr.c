/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:33:04 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:10:52 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of a specific character in a string.
 *
 * This function searches for the first occurrence of the character 'c'
 * (converted to an unsigned char) in the string 'str'. The search starts from
 * the beginning of the string and continues until the null-terminator character
 * is encountered or the specified character is found.
 *
 * @param str The string to be searched.
 * @param c The character to be located.
 * @return A pointer to the located character within the string, or NULL if the
 * character is not found.
 */
char	*ft_strchr(const char *str, int c)
{
	size_t	a;

	a = -1;
	while (++a <= ft_strlen(str))
		if (((unsigned char *)str)[a] == (unsigned char) c)
			return ((char *)str + a);
	return (NULL);
}
