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
 * @brief Applies a given function to each character of a string, creating a new
 * transformed string.
 *
 * This function iterates through each character of the string 's' and applies
 * the function 'f' to each character along with its corresponding index. The
 * result of applying the function to each character is used to construct a new
 * string, which is dynamically allocated. The new string is null-terminated,
 * and a pointer to it is returned.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character along with its index.
 * @return A pointer to the newly allocated transformed string, or NULL if
 * memory allocation fails.
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
