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
 * @brief 
 *
 * @param str
 * @param c
 * @return size_t
 */
size_t	ft_pos_search(const char *str, int c)
{
	size_t	a;
	size_t	len;

	a = -1;
	len = ft_strlen(str);
	while (++a <= len)
		if (str[a] == c)
			return (a);
	return (-1);
}

size_t	ft_skip(const char *str, int c)
{
	size_t	a;
	size_t	len;

	a = -1;
	len = ft_strlen(str);
	while (++a < len)
		if (str[a] != c)
			return (a);
	return (-1);
}

size_t	find_size(const char *s, char c)
{
	size_t	start;
	size_t	sep;
	size_t	i;
	size_t	sk;

	start = 0;
	i = 0;
	sep = 0;
	while (sep != (size_t) -1)
	{
		sk = ft_skip(s + (start + sep), c);
		if (sk != (size_t) - 1)
			start = start + sep + sk;
		else if (sk == (size_t) - 1)
			break ;
		sep = ft_pos_search((s + start), c);
		i++;
	}
	return (i);
}

char	**ft_terminator(const char *s, char c, char **splited)
{
	size_t	start;
	size_t	sep;
	size_t	i;
	size_t	sk;

	start = 0;
	i = 0;
	sep = 0;
	while (sep != (size_t) -1)
	{
		sk = ft_skip(s + (start + sep), c);
		if (sk != (size_t) - 1)
			start = start + sep + sk;
		else if (sk == (size_t) - 1)
			break ;
		sep = ft_pos_search((s + start), c);
		if (sep != (size_t) - 1)
			splited[i] = ft_substr(s, start, sep);
		else if (sep == (size_t) - 1)
			splited[i] = ft_substr(s, start, ft_strlen(s + start));
		i++;
	}
	splited[i] = NULL;
	return (splited);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;

	if (!s)
		splited = (char **) malloc(sizeof(char *));
	else
		splited = (char **) malloc((find_size(s, c) + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	return (ft_terminator(s, c, splited));
}
