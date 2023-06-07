/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:25:53 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/05 16:25:53 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

/*
char	**ft_split(char *str, char)
{
	int		i;
	int		i2;
	int		i3;
	int		a;
	char	**final;

	final = malloc(sizeof(char **) * 9999);
	i = -1;
	i2 = 0;
	while (str[++i])
	{
		if (str[i] > 32)
		{
			i3 = 0;
			while (str[i3] > 32)
				a++;
			final[i2] = malloc(sizeof(char **) * a + 1);
			i3 = 0;
			while (str[i] > 32)
			{
				final[i2][i3] = str[i];
				i3++;
				i++;
			}
			final[i2][i3] = '\0';
			i2++;
		}
	}
	final[i2] = 0;
	return (final);
}
*/