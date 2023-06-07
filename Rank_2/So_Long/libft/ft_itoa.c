/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:37:51 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/15 15:43:42 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digits(long int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	if (n <= 9)
		i++;
	else
		i = i + 1 + count_digits(n / 10);
	return (i);
}

char	*writing(long int n, char *ito, size_t size)
{
	if (n < 0)
	{
		ito[0] = '-';
		if (n <= -2147483648)
		{
			ito[1] = '2';
			n = -147483648;
		}
		n = n * (-1);
	}
	if (n <= 9)
		ito[size] = n + 48;
	else
	{
		ito[size] = n % 10 + 48;
		ito = writing(n / 10, ito, size - 1);
	}
	return (ito);
}

char	*ft_itoa(int n)
{
	size_t		size;
	char		*ito;

	size = count_digits(n);
	ito = (char *) malloc(size * sizeof(char) + 1);
	if (!ito)
		return (NULL);
	ito = writing(n, ito, size - 1);
	ito[size] = '\0';
	return (ito);
}
