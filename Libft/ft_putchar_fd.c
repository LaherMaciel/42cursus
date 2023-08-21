/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:56:34 by marvin            #+#    #+#             */
/*   Updated: 2022/11/15 14:39:15 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a character to a file descriptor.
 *
 * This function writes the character 'c' to the specified file descriptor 'fd'.
 * It uses the `write` system call to perform the writing operation.
 *
 * @param c The character to be written.
 * @param fd The file descriptor to which the character will be written.
 */
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
