/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:23:57 by lwencesl          #+#    #+#             */
/*   Updated: 2022/10/28 21:17:53 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given integer represents a valid ASCII character.
 *
 * This function determines whether the provided integer 'a' is within the range
 * of valid ASCII characters, which is from 0 to 127 inclusive.
 *
 * @param a The integer value to be checked.
 * @return 1 if 'a' is a valid ASCII character, 0 otherwise.
 */
int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	return (0);
}
