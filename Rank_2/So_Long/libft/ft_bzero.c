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
 * @brief This function sets a block of memory to zero. It takes
 * a pointer s to the memory block and the number of bytes n to zero out.
 * The function iterates through each byte of the memory block and assignsa
 *  value of zero. It is primarily used for initializing memory regions or
 * clearing data structures before use.
 * 
 * @param s 
 * @param n 
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((unsigned char *) s)[i] = 0;
}
