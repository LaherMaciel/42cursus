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

int	new_sign(const char *str, int i, int sign)
{
	if (str[i] == '-')
		sign = sign * (-1);
	return (sign);
}

/**
 * @brief Converts a string to an integer.
 *
 * This function takes a string as input and converts it to an integer
 * representation. It skips leading whitespace characters, processes optional
 * sign (+/-), and then iterates through the digits in the string to calculate
 * the resulting integer value. If the input string represents a value that is
 * out of the valid range for a `size_t` (which is the return type), the
 * function handles the edge cases and returns the appropriate extreme value.
 *
 * @param str The input string to be converted to an integer.
 * @return size_t The integer value converted from the input string.
 */
size_t	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	c;

	sign = 1;
	c = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = new_sign(str, i, sign);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		c = (c * 10) + (str[i++] - '0');
		if (c == 922337203685477580 && str[i] >= 7)
		{
			if (c == 922337203685477580 && sign == -1)
				return (-9223372036854775807);
			return (9223372036854775807);
		}
	}
	return (c * sign);
}
