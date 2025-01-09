/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:50:36 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/02 18:25:44 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
