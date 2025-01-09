/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:06:47 by marvin            #+#    #+#             */
/*   Updated: 2022/11/15 14:39:18 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a string followed by a newline character to a file descriptor.
 *
 * This function writes the string 's' to the specified file descriptor 'fd',
 * followed by a newline character. It uses the `ft_putstr_fd` function to write
 * the string and then appends a newline character using the `write` system
 * call.
 *
 * @param s The string to be written.
 * @param fd The file descriptor to which the string and newline will be
 * written.
 */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}
