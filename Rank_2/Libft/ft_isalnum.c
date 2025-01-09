/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:57:19 by lwencesl          #+#    #+#             */
/*   Updated: 2022/10/28 20:13:07 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given character is alphanumeric.
 *
 * This function determines whether the provided character 'a' is an
   alphanumeric character, which includes digits (0-9) and both lowercase (a-z)
   and uppercase (A-Z) letters.
 *
 * @param a The character to be checked.
 * @return int 1 if 'a' is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int a)
{
	if ((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	return (0);
}
