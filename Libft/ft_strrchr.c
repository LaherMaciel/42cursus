/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:25:14 by lwencesl          #+#    #+#             */
/*   Updated: 2022/10/28 18:25:14 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the last occurrence of a specific character in a string.
 *
 * This function searches for the last occurrence of the character 'c'
 * (converted to an unsigned char) in the string 'str'. The search starts from
 * the end of the string and proceeds towards the beginning. If the character
 * 'c' is found, a pointer to its location within the string is returned. If 'c'
 * is not found, NULL is returned.
 *
 * @param str The string to be searched.
 * @param c The character to be located.
 * @return A pointer to the last occurrence of 'c' within 'str', or NULL if 'c'
 * is not found in the string.
 */
char	*ft_strrchr(const char *str, int c)
{
	int	a;

	a = ft_strlen(str) + 1;
	while (--a >= 0)
		if (((unsigned char *)str)[a] == (unsigned char) c)
			return ((char *)str + a);
	return (0);
}
