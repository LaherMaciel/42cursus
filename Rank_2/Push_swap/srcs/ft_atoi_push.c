/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <lawences@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:59:17 by lawences          #+#    #+#             */
/*   Updated: 2024/06/25 22:05:54 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	aux(const char *str, size_t index, size_t number, size_t sign)
{
	while (ft_isdigit(str[index]))
	{
		number = number * 10;
		number = number + (str[index] - '0');
		index++;
		if (number > INT_MAX)
			break ;
	}
	if (str[index])
		return (2147483650);
	if (sign != 1)
		return (-number);
	return (number);
}

/**
 * @brief Convert a string to an integer.
 *
 * This function converts a string representation of an integer into an integer
 * value.
 *
 * @param str The input string containing the integer representation.
 * @return The integer value represented by the input string.
 */
size_t	ft_atoi_push(const char *str)
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
	return (aux(str, index, number, sign));
}
