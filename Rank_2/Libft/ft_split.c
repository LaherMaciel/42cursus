/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:04:51 by marvin            #+#    #+#             */
/*   Updated: 2023/06/20 16:10:44 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Frees all memory allocated for the split array.
 *
 * This function iterates through the split array, freeing each substring, then
 * frees the array itself, and finally returns NULL to indicate all memory has
 * been cleared.
 *
 * @param split The array of strings to free.
 * @return Always returns NULL as a signal that the memory has been cleared.
 */
static char	**free_all(char **split)
{
	int	i;

	i = -1;
	if (split)
	{
		while (split[++i])
			free(split[i]);
		free(split);
	}
	return (NULL);
}

/**
 * @brief Skips over or finds the next occurrence of a character depending on
 * the mode specified.
 *
 * This function advances the index 'i' in the string 's' either by skipping
 * over the character 'c' or by finding the next instance where 's[i]' is not
 * 'c', based on the 'skip_or_find' flag.
 *
 * @param s The string in which to find or skip characters.
 * @param c The character to find or skip.
 * @param i The current position in the string.
 * @param skip_or_find Flag to determine behavior: 0 to skip 'c', 1 to find not
 * 'c'.
 * @return The new position in the string after processing.
 */
static int	ft_skip_or_find_set(char const *s, char c,
		int i, int skip_or_find)
{
	if (skip_or_find == 0)
		while (s[i] == c)
			i++;
	else if (skip_or_find == 1)
		while (s[i] != c)
			i++;
	return (i);
}

/**
 * @brief Splits the string 's' into an array of strings divided by the
 * character 'c'.
 *
 * This function uses ft_skip_or_find_set to manage indices as it iterates
 * through 's', creating new strings from segments of 's' that do not include
 * the separator 'c'. Memory allocation failures are handled by freeing already
 * allocated memory.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @param split Pre-allocated array to hold the resulting substrings.
 * @return The filled array of strings or NULL if a memory allocation fails.
 */
static char	**ft_splitter(char const *s, char c, char **split)
{
	int	index;
	int	i;
	int	j;

	index = ft_skip_or_find_set(s, c, 0, 0);
	i = 0;
	while (s[index])
	{
		j = ft_skip_or_find_set(s, c, index, 1);
		split[i] = (char *) malloc((j - index + 1) * sizeof(char));
		if (!split[i])
			return (free_all(split));
		j = 0;
		while ((s[index] && s[index] != c))
		{
			split[i][j++] = s[index];
			index++;
		}
		split[i++][j] = '\0';
		index = ft_skip_or_find_set(s, c, index, 0);
	}
	split[i] = NULL;
	return (split);
}

int	count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	i = ft_skip_or_find_set(s, c, i, 0);
	words = 0;
	if (s[i])
		words = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			i = ft_skip_or_find_set(s, c, i, 0);
			if (!s[i])
				break ;
			words++;
		}
		else
			i++;
	}
	return (words);
}

/**
 * @brief Splits the string 's' using the character 'c' as a delimiter,
 * returning an array of strings.
 *
 * This function counts the number of words in 's' that are separated by 'c',
 * allocates memory for the array, and then uses ft_splitter to create the
 * actual array of strings. If the input string is NULL, it immediately returns
 * NULL.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return An array of strings resulting from the split, or NULL if there was an
 * error.
 */
char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = (char **) malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_splitter(s, c, split);
	return (split);
}
