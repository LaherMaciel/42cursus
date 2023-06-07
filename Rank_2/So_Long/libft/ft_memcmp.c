/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:19:18 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/02 19:15:23 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			a;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *) str1;
	c2 = (unsigned char *) str2;
	a = -1;
	while (++a < n)
	{
		if (c1[a] != c2[a])
		{
			if ((c1[a] - c2[a]) < 0)
				return (-1);
			else
				return (1);
		}
	}
	return (0);
}
