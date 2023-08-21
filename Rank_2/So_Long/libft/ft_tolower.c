/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:46:03 by lwencesl          #+#    #+#             */
/*   Updated: 2022/10/28 19:46:03 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts an uppercase character to its lowercase equivalent.
 *
 * This function takes an ASCII character 'a' as input and checks if it
 * represents an uppercase letter (A-Z) based on its ASCII value. If 'a' is an
 * uppercase letter, it converts it to its lowercase equivalent by adding 32 to
 * its ASCII value, effectively converting between the uppercase and lowercase
 * letters. The modified character is then returned. If 'a' is not an uppercase
 * letter, it is returned unchanged.
 *
 * @param a The ASCII value of the character to be converted to lowercase.
 * @return The lowercase equivalent of 'a' if it's an uppercase letter, or 'a'
 * itself if it's not an uppercase letter.
 */
int	ft_tolower(int a)
{
	if (a >= 65 && a <= 90)
		a = a + 32;
	return (a);
}
