/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:25:14 by lwencesl          #+#    #+#             */
/*   Updated: 2022/10/28 18:25:14 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	a;

	a = ft_strlen(str) + 1;
	while (--a >= 0)
		if (((unsigned char *)str)[a] == (unsigned char) c)
			return ((char *)str + a);
	return (0);
}
