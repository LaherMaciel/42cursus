/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:41:35 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/06 17:48:47 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		clean(int newline, int x, int y, char *buffer);
size_t	ft_strlen(char *a);
char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (read(fd, 0, 0) || BUFFER_SIZE <= 0)
	{
		i = 0;
		while (buffer[i])
			buffer[i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while ((buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0))
	{
		line = ft_strjoin(line, buffer);
		if (clean (0, 0, 0, buffer) == 1)
			break ;
	}
	return (line);
}
