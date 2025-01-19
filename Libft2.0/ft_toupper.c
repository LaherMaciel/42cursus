/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:47:47 by lwencesl          #+#    #+#             */
/*   Updated: 2022/10/28 19:47:47 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a lowercase character to its uppercase equivalent.
 *
 * This function takes an ASCII character 'c' as input and checks if it
 * represents a lowercase letter (a-z) based on its ASCII value. If 'c' is a
 * lowercase letter, it converts it to its uppercase equivalent by subtracting
 * 32 from its ASCII value, effectively converting between the lowercase and
 * uppercase letters. The modified character is then returned. If 'c' is not a
 * lowercase letter, it is returned unchanged.
 *
 * @param c The ASCII value of the character to be converted to uppercase.
 * @return The uppercase equivalent of 'c' if it's a lowercase letter, or 'c'
 * itself if it's not a lowercase letter.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
