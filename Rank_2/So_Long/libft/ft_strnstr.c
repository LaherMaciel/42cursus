/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:44:42 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:17:44 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief locate a substring in a string
 *
 * @param big
 * @param little
 * @param len size of the main string
 * @return char*
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	if (little[0] == '\0')
		return ((char *)big);
	if (len <= 0)
		return (NULL);
	a = 0;
	while (big[a])
	{
		b = 0;
		while (((char *)big)[a + b] == ((char *)little)[b] \
		&& (a + b) < len)
		{
			if (little[b] == '\0')
				return ((char *)big + a);
			b++;
		}
		if (little[b] == '\0')
			return ((char *)big + a);
		a++;
	}
	return (NULL);
}
