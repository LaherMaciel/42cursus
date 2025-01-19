/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:54:54 by lwencesl          #+#    #+#             */
/*   Updated: 2022/10/29 22:35:37 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets a block of memory to zero.
 *
 * This function takes a pointer s to the memory block and the number of bytes n
 * to zero out. It iterates through each byte of the memory block and assigns a
 * value of zero.
 *
 * @param s Pointer to the memory block.
 * @param n Number of bytes to zero out.
 *
 * @note The function is commonly used for initializing memory regions or
 * clearing data structures before use.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((char *) s)[i] = 0;
}
