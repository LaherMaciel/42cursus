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
#include "checker.h"

int	new_sign(char *str, int i, int sign)
{
	if (str[i] == '-')
		sign = sign * (-1);
	return (sign);
}

long	ft_atoi(char *str)
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = (c * 10) + (str[i++] - '0');
		if (c >= 922337203685477580 && str[i] >= 7)
		{
			if (c >= 922337203685477580 && sign == -1)
				return (-9223372036854775807);
			return (9223372036854775807);
		}
	}
	return (c * sign);
}
