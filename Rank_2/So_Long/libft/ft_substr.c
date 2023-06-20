/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:21:40 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:57:55 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 *
 * @param s the string
 * @param start where should start coping
 * @param len where should end the copy
 * @return char*
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*d;

	a = 0;
	if (len == 0)
		len = ft_strlen(s);
	while ((start + a) < ft_strlen(s) && a < len)
		a++;
	d = (char *) malloc(a * sizeof(char) + 1);
	if (!d)
		return (NULL);
	a = 0;
	while ((start + a) < ft_strlen(s) && a < len)
	{
		d[a] = s[start + a];
		a++;
	}
	d[a] = '\0';
	return (d);
}
