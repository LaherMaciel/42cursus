/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:28:14 by marvin            #+#    #+#             */
/*   Updated: 2023/06/20 16:12:34 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 *
 * @param s
 * @param f
 * @return char*
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	siz;
	unsigned int	i;

	siz = ft_strlen(s);
	new = (char *) malloc(siz * sizeof(char) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < siz)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
