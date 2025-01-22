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

#include "../../include/libft.h"

static size_t	ft_strlen_sub(char *str, size_t i, size_t quotes, size_t open)
{
	while (str[i])
	{
		if (str[i] == '\'' && open == 0)
		{
			quotes++;
			open = 1;
		}
		else if (str[i] == '\"' && open == 0)
		{
			quotes++;
			open = 2;
		}
		else if ((str[i] == '\'' && open == 1)
			|| (str[i] == '\"' && open == 2))
		{
			quotes++;
			open = 0;
		}
		i++;
	}
	return (i - quotes);
}

static int	remove_quotes_ifloop(char *str, size_t i, size_t *open)
{
	if (str[i] == '\'' && *open == 0)
		*open = 1;
	else if (str[i] == '\"' && *open == 0)
		*open = 2;
	else if ((str[i] == '\'' && *open == 1)
		|| (str[i] == '\"' && *open == 2))
		*open = 0;
	else
		return (1);
	return (0);
}

static char	*remove_quotes(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	open;

	new_str = ft_calloc(ft_strlen_sub(str, 0, 0, 0), sizeof(char) + 2);
	i = 0;
	j = 0;
	open = 0;
	while (str[i] && j < ft_strlen_sub(str, 0, 0, 0))
	{
		if (remove_quotes_ifloop(str, i, &open) == 0)
			i++;
		else
			new_str[j++] = str[i++];
	}
	free(str);
	return (new_str);
}

char	*for_pipex(char *d)
{
	if (ft_strcmp(d, "''") == 0)
	{
		free(d);
		return (ft_calloc(1, sizeof(char)));
	}
	if (ft_strncmp(d, "\' \'", 3) == 0)
	{
		free(d);
		d = ft_calloc(1, sizeof(char));
		d = " ";
	}
	return (remove_quotes(d));
}

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
 *
 * @note removed this part of the code that was between a = 0 and the while loop
 * before the malloc. if (len == 0) len = ft_strlen(s);
 */
char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*d;

	a = 0;
	if (!s)
		return (NULL);
	while ((start + a) < ft_strlen(s) && a < len)
		a++;
	d = ft_calloc((a + 1), sizeof(char));
	if (!d)
		return (NULL);
	a = 0;
	while ((start + a) < ft_strlen(s) && a < len)
	{
		d[a] = s[start + a];
		a++;
	}
	return (for_pipex(d));
}
