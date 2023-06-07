/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:08:35 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/25 23:37:43 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	clean(int newline, int x, int y, char *buffer)
{
	while (buffer[x])
	{
		if (newline == 1)
			buffer[y++] = buffer[x];
		if (buffer[x] == '\n')
			newline = 1;
		buffer[x] = 0;
		x++;
	}
	return (newline);
}

size_t	str_length(char *a)
{
	size_t	i;

	if (!a)
		return (0);
	i = 0;
	while (a[i] != '\0' && a[i] != '\n')
		i++;
	if (a[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sjoin;
	size_t	i;

	sjoin = (char *) malloc((str_length(s1) + str_length(s2)) * sizeof(char) + 1);
	if (!sjoin)
		return (NULL);
	i = -1;
	while (s1 && s1[++i] != '\0')
		sjoin[i] = s1[i];
	free(s1);
	if (!s1)
		i = 0;
	while (*s2)
	{
		sjoin[i++] = *s2;
		if (*s2++ == '\n')
			break ;
	}
	sjoin[i] = '\0';
	return (sjoin);
}
