/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:35:24 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/02 17:56:55 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ds;
	char	*sc;

	sc = (char *) src;
	ds = dest;
	if (sc < ds)
		while (n--)
			ds[n] = sc[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
