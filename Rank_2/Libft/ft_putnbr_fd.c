/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:11:28 by marvin            #+#    #+#             */
/*   Updated: 2022/11/15 14:39:22 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes an integer as a string to a file descriptor.
 *
 * This function writes the integer 'n' to the specified file descriptor 'fd' as
 * a string of characters. It handles both positive and negative integers. The
 * writing is performed recursively, breaking down the integer into digits.
 *
 * @param n The integer to be written.
 * @param fd The file descriptor to which the integer will be written.
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	aux;

	if (n < 0)
	{
		write (fd, "-", 1);
		if (n <= -2147483648)
		{
			write (fd, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	if (n <= 9)
	{
		aux = n + 48;
		write (fd, &aux, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		aux = n % 10 + 48;
		write (fd, &aux, 1);
	}
}
