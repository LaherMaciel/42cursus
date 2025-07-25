/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:12:22 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/23 15:41:12 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
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

/**
 * @brief Allocates and initializes memory for an array of elements.

* This function allocates memory for an array containing 'n' elements, each of
  size 'size' bytes. The allocated memory is then initialized to zero using the
  ft_bzero function.

* @param n The number of elements in the array.
* @param size The size of each element in bytes.
* @return A pointer to the allocated and initialized memory, or NULL if
  allocation fails.
 */
void	*ft_calloc(size_t n, size_t size)
{
	void	*new_block;
	size_t	j;

	new_block = malloc(n * size);
	if (!new_block)
		return (NULL);
	j = -1;
	while (++j < n * size)
		((char *) new_block)[j] = 0;
	return (new_block);
}

/**
 * @brief Checks if a given integer represents a digit character.
 *
 * This function determines whether the provided integer 'i' corresponds to a
 * digit character, which includes the digits 0 through 9.
 *
 * @param i The integer value to be checked.
 * @return 1 if 'i' represents a digit character, 0 otherwise.
 */
int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	return (0);
}

int	ft_isdigit2(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (i >= 48 && i <= 57)
			return (1);
	return (0);
}
