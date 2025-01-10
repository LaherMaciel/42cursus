/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:54:27 by marvin            #+#    #+#             */
/*   Updated: 2023/06/20 16:11:11 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates two strings to create a new dynamically allocated string.
 *
 * This function concatenates the strings 's1' and 's2' to create a new string.
 * It allocates memory for the concatenated string, copies the characters from
 * 's1' and 's2' into it, and adds a null-terminator at the end. The resulting
 * concatenated string is returned as a newly allocated memory block.
 *
 * @param s1 The first string to be concatenated.
 * @param s2 The second string to be concatenated.
 * @return A pointer to the newly allocated concatenated string, or NULL if
 * memory allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	i;
	size_t	j;

	sjoin = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!sjoin)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		sjoin[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
	{
		sjoin[i] = s2[j];
		i++;
	}
	sjoin[i] = '\0';
	return (sjoin);
}

char	*ft_strjoin2(char *s1, char const *s2)
{
	char	*sjoin;
	size_t	i;
	size_t	j;

	sjoin = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!sjoin)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		sjoin[i] = s1[i];
	free(s1);
	j = -1;
	while (s2[++j] != '\0')
	{
		sjoin[i] = s2[j];
		i++;
	}
	sjoin[i] = '\0';
	return (sjoin);
}
