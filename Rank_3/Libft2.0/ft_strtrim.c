/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:35:01 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/07 21:37:32 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_in(char c, const char *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

size_t	ft_getsize(const char *str, const char *set)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(str);
	i = 0;
	while (ft_in(str[i], set) != 0 && str[i])
		i++;
	if (i == size)
		return (0);
	while (ft_in(str[size - 1], set) != 0)
		size --;
	return (size - i);
}

/**
 * @brief Creates a new string by removing specified characters from the
 * beginning and end of a string.
 *
 * This function creates a new string by removing characters from the beginning
 * and end of the input string 'str' that are found in the 'set' string. It
 * calculates the size of the resulting trimmed string, allocates memory for it,
 * and constructs the trimmed string. The trimmed string is null-terminated, and
 * a pointer to it is returned.
 *
 * @param str The input string to be trimmed.
 * @param set The set of characters to be removed from the beginning and end of
 * 'str'.
 * @return A pointer to the newly allocated trimmed string, or NULL if memory
 * allocation fails or if 'str' is NULL.
 */
char	*ft_strtrim(const char *str, const char *set)
{
	size_t		size;
	char		*trim;
	size_t		i;
	size_t		j;

	if (!str)
		return (NULL);
	size = ft_getsize(str, set);
	trim = (char *)malloc(size * sizeof(char) + 1);
	if (!trim)
		return (NULL);
	trim[size] = '\0';
	i = 0;
	j = -1;
	while (ft_in(str[i], set) && str[i])
		i++;
	while (++j < size)
		trim[j] = str[i + j];
	return (trim);
}
