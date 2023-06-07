/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:35:01 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/07 21:37:32 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_in(char c, const char *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

size_t	ft_getsize(const char *str, const char *set)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(str);
	i = 0;
	while (ft_in(str[i], set) != 0 && str[i])
		i++;
	if (i == size)
		return (0);
	while (ft_in(str[size - 1], set) != 0)
		size --;
	return (size - i);
}

char	*ft_strtrim(const char *str, const char *set)
{
	size_t		size;
	char		*trim;
	size_t		i;
	size_t		j;

	if (!str)
		return (NULL);
	size = ft_getsize(str, set);
	trim = (char *)malloc(size * sizeof(char) + 1);
	if (!trim)
		return (NULL);
	trim[size] = '\0';
	i = 0;
	j = -1;
	while (ft_in(str[i], set) && str[i])
		i++;
	while (++j < size)
		trim[j] = str[i + j];
	return (trim);
}
