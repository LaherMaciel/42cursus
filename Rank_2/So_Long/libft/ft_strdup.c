/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:38:25 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/02 18:20:59 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	a;
	size_t	i;

	a = ft_strlen(s);
	c = (char *) malloc(a * sizeof(char) + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < a)
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
