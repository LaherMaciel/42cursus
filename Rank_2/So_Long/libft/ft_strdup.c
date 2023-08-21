/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:38:25 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:10:59 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicates a string by creating a new dynamically allocated copy.
 *
 * This function creates a new string that is an exact copy of the input string
 * 's'. It allocates memory for the new string, copies the characters from 's'
 * into it, and adds a null-terminator at the end.
 *
 * @param s The input string to be duplicated.
 * @return A pointer to the newly allocated duplicated string, or NULL if memory
 * allocation fails.
 */
char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	a;
	size_t	i;

	a = ft_strlen(s);
	c = (char *) malloc(a * sizeof(char) + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < a)
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
