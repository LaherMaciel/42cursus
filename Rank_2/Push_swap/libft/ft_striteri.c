/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:34:53 by marvin            #+#    #+#             */
/*   Updated: 2023/06/20 16:11:06 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a given function to each character of a string along with its
 * index.
 *
 * This function iterates through each character of the string 's' and applies
 * the function 'f' to each character along with its corresponding index. The
 * index is passed as the first argument to the function 'f', and a pointer to
 * the character is passed as the second argument.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character along with its index.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(s))
		f(i, &s[i]);
}
