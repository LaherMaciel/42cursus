/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:57:33 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/06 17:48:18 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cleangnl(int newline, int x, int y, char *buffer);
size_t	ft_strlengnl(char *a);
char	*ft_strjoingnl(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
	{
		i = 0;
		if (fd < 0 || fd > FOPEN_MAX)
			return (NULL);
		while (buffer[fd][i])
			buffer[fd][i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while ((buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0))
	{
		line = ft_strjoingnl(line, buffer[fd]);
		if (cleangnl (0, 0, 0, buffer[fd]) == 1)
			break ;
	}
	return (line);
}
