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

void	ft_putnbr_fd(int n, int fd)
{
	char	aux;

	if (n < 0)
	{
		write (fd, "-", 1);
		if (n <= -2147483648)
		{
			write (fd, "2", 1);
			n = -147483648;
		}
		n = n * (-1);
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
