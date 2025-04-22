/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:35:50 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:12:22 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * This function calculates the length of the null-terminated string 'a' by
 * iterating through its characters until the null-terminator ('\0') is
 * encountered. It counts the number of characters before the null-terminator
 * and returns this count as the length of the string.
 *
 * @param a The null-terminated string whose length is to be calculated.
 * @return The length of the string (number of characters before the
 * null-terminator, '\0' is not included).
 */
size_t	ft_strstrlen(char **a)
{
	size_t	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
