/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:21:40 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:57:55 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new substring from a given string starting from a specified
 * index and with a specified length.
 *
 * This function creates a new string that is a substring of the input string
 * 's'. The substring starts at the index 'start' and has a length of 'len'
 * characters. If 'len' is 0, the function considers the entire string from
 * 'start' to the end. Memory is allocated for the new substring, which is
 * null-terminated, and a pointer to the substring is returned.
 *
 * @param s The input string from which the substring will be extracted.
 * @param start The starting index of the substring within 's'.
 * @param len The length of the substring to be extracted.
 * @return A pointer to the newly allocated substring, or NULL if memory
 * allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*d;

	a = 0;
	if (len == 0)
		len = ft_strlen(s);
	while ((start + a) < ft_strlen(s) && a < len)
		a++;
	d = (char *) malloc(a * sizeof(char) + 1);
	if (!d)
		return (NULL);
	a = 0;
	while ((start + a) < ft_strlen(s) && a < len)
	{
		d[a] = s[start + a];
		a++;
	}
	d[a] = '\0';
	return (d);
}
