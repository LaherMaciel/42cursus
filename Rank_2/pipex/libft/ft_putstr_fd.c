/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:01:00 by marvin            #+#    #+#             */
/*   Updated: 2022/11/15 14:39:25 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a string to a file descriptor.
 *
 * This function writes the string 's' to the specified file descriptor 'fd'
 * using the `write` system call. It iterates through the characters in the
 * string and writes each character individually to the file descriptor.
 *
 * @param s The string to be written.
 * @param fd The file descriptor to which the string will be written.
 */
void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(s))
		write (fd, &s[i], 1);
}
