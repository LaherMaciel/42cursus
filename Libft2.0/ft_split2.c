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

#include "../../include/libft.h"

// && str[a] != '\"'
static size_t	ft_pos_search(const char *str, int c)
{
	size_t	a;
	size_t	len;
	char	quote;

	a = -1;
	len = ft_strlen(str);
	if (ft_strncmp(str, "\' \'", 3) == 0)
		return (3);
	while (++a <= len)
	{
		if (str[a] == '\"' || str[a] == '\'')
		{
			quote = str[a];
			a++;
			while (str[a] && str[a] != quote)
				a++;
		}
		if (str[a] == c)
			return (a);
	}
	return (-1);
}

static size_t	ft_skip(const char *str, int c)
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

static size_t	find_size(const char *s, char c)
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

static char	**ft_terminator(const char *str, char c, char **splited)
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
		sk = ft_skip(str + (start + sep), c);
		if (sk != (size_t) - 1)
			start = start + sep + sk;
		else if (sk == (size_t) - 1)
			break ;
		sep = ft_pos_search((str + start), c);
		if (sep != (size_t) - 1)
			splited[i] = ft_substr2(str, start, sep);
		else if (sep == (size_t) - 1)
			splited[i] = ft_substr2(str, start, ft_strlen(str + start));
		i++;
	}
	splited[i] = NULL;
	return (splited);
}

/**
 * @brief split the string in to a array of strings
 * 
 * @param s the main string
 * @param c the spliter
 * @return char** the array of strings
 * 
 * @example It can now read input like -> "e entao" naquele dia"o
 * 		jorge aconteceu"
 * 
 * SPLIT 2
 * line = "e então" naquele dia"o jorge aconteceu"
 * [0] = e então
 * [1] = naquele
 * [2] = diao jorge aconteceu
 * 
 * and --> "e entao" naquele dia "o jorge aconteceu"
 * SPLIT 2
 * [0] = e entao
 * [1] = naquele
 * [2] = dia
 * [3] = o jorge aconteceu
 */
char	**ft_split2(char const *s, char c)
{
	char	**splited;

	if (!s)
		splited = (char **) ft_calloc(0, sizeof(char *));
	else
		splited = (char **) ft_calloc((find_size(s, c) + 1), sizeof(char *));
	if (!splited)
		return (NULL);
	splited = ft_terminator(s, c, splited);
	return (splited);
}
