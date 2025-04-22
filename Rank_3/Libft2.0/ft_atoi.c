/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:54:06 by lwencesl          #+#    #+#             */
/*   Updated: 2022/10/28 18:54:06 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert a string to an integer.
 *
 * This function converts a string representation of an integer into an integer
 * value.
 *
 * @param str The input string containing the integer representation.
 * @return The integer value represented by the input string.
 */
size_t	ft_atoi(const char *str)
{
	size_t	index;
	size_t	sign;
	size_t	number;

	sign = 1;
	number = 0;
	index = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign++;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		number = number * 10;
		number = number + (str[index] - '0');
		index++;
	}
	if (sign != 1)
		return (-number);
	return (number);
}
